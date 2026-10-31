#include "bn_core.h"
#include "bn_log.h"
#include "bn_string.h"
#include "bn_keypad.h"
#include "bn_regular_bg_map_cell_info.h"
#include "bn_sprite_text_generator.h"
#include "common_fixed_8x8_sprite_font.h"
#include "bn_regular_bg_items_logo.h"
#include "bn_blending_actions.h"
#include "bn_vector.h"
#include "bn_sound_items.h"
#include "bn_sound_actions.h"
#include "bn_music_items.h"
#include "bn_music_actions.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_palettes.h"
#include "bn_bg_palettes_actions.h"
#include "bn_sprite_palettes_actions.h"
#include "bn_colors.h"
#include "bn_optional.h"

#include "camera.h"
#include "player.h"
#include "game_level.h"
#include "collision_check.h"
#include "game_states.h"
#include "timer.h"
#include "screen_fade.h"

namespace menu_loop {
    void update() {
        bn::regular_bg_ptr logo = bn::regular_bg_items::logo.create_bg(0, -40);

        bn::sprite_text_generator text_gen(common::fixed_8x8_sprite_font);
        bn::vector<bn::sprite_ptr, 128> text_sprites;

        bn::music_item main_theme = bn::music_items::old_doll;
        main_theme.play(0, true);

        text_gen.set_center_alignment();

        bool start_hint_is_shown = false;
        bool start_button_pressed = false;
        bool transition_to_next_screen = false;
        bool transition_to_main_loop = false;

        bn::bg_palettes::set_fade_color(bn::colors::black);
        bn::bg_palettes::set_fade_intensity(1);

        bn::sprite_palettes::set_fade_color(bn::colors::black);

        bn::optional<bn::sprite_palettes_fade_to_action> spr_transition;
        spr_transition.emplace(120, 0);

        bn::optional<bn::bg_palettes_fade_to_action> bg_transition;
        bg_transition.emplace(120, 0);
        
        bn::optional<bn::music_volume_to_action> music_transition;
        music_transition.emplace(120, 1);

        while (!transition_to_next_screen) {
            if (!bg_transition->done()) 
            {
                bg_transition->update();
                spr_transition->update();
                music_transition->update();

                if (bg_transition->done() && !start_hint_is_shown) {
                    text_gen.generate(0, 30, "PRESS START BUTTON", text_sprites);
                    start_hint_is_shown = true;

                    if (start_button_pressed) {
                        bg_transition.reset();
                        spr_transition.reset();
                        music_transition.reset();
                    }
                } else if (spr_transition->done() && start_button_pressed && !transition_to_next_screen) {
                    BN_LOG("GOING TO NEXT SCREEN");
                    text_gen.set_blending_enabled(false);
                    transition_to_next_screen = true;
                }
            }

            if (!start_button_pressed && bn::keypad::start_pressed()) {
                bn::sound_items::menu_select.play();

                start_button_pressed = true;

                bg_transition.emplace(120, 1);
                spr_transition.emplace(120, 1);
                music_transition.emplace(120, 0);
            }

            bn::core::update();
        }
    }
}

namespace core_loop {
    void update() {

        // Create level manager instance
        map _map(bn::regular_bg_items::connie_house);

        // Create player object
        player connie(_map);

        // Assing camera to background
        _map.bg_ptr.set_camera(connie.cameraPtr);

        bn::bg_palettes::set_fade_intensity(1);
        bn::sprite_palettes::set_fade_intensity(1);

        bool fade_in_finished = false;

        while (true) {
            switch (fade_in_finished) {
                case false:
                    fade(120, 0);
                    fade_in_finished = true;
                    break;
            }

            connie.update();

            bn::core::update();
        }
    }
}

int main()
{
    bn::core::init();

    BN_LOG("GAME INIT. HELLO, WORLD!");

    // Create instance that tracks game states
    game_states gameStates;
    game_states* states = &gameStates;

    while (true) {
        states->IN_MAIN_MENU = true;
        menu_loop::update();

        states->IN_MAIN_MENU = false;
        bn::core::update();

        states->IN_GAME = true;
        core_loop::update();
        bn::core::update();
    }

    BN_LOG("EXIT INITIATED");
    return 1;
}
