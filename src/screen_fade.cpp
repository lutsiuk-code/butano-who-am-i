#include "screen_fade.h"

bn::optional<bn::sprite_palettes_fade_to_action> spr_transition;
bn::optional<bn::bg_palettes_fade_to_action> bg_transition;

bool color_set;

void fade(int duration_in_frames, int final_value) {
    if (!color_set) {
        bn::bg_palettes::set_fade_color(bn::colors::black);
        bn::sprite_palettes::set_fade_color(bn::colors::black);
        color_set = true;
    }

    spr_transition.emplace(duration_in_frames, final_value);
    bg_transition.emplace(duration_in_frames, final_value);

    while (!spr_transition->done()) {
        spr_transition->update();
        bg_transition->update();
        bn::core::update();
    }

    spr_transition.reset();
    bg_transition.reset();
}