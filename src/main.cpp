#include "bn_core.h"
#include "bn_log.h"
#include "bn_string.h"
#include "bn_regular_bg_map_cell_info.h"
#include "bn_sprite_text_generator.h"
#include "common_fixed_8x8_sprite_font.h"

#include "camera.h"
#include "player.h"
#include "game_level.h"
#include "collision_check.h"

int main()
{
    bn::core::init();

    BN_LOG("GAME INIT. HELLO, WORLD!");

    // ================= SETTING UP THE MANAGERS/INSTANCES =================

    // Create level manager instance
    map _map(bn::regular_bg_items::connie_house);

    // Create player object
    player connie(_map);

    // Assing camera to background
    _map.bg_ptr.set_camera(connie.cameraPtr);

    // Create text generator instance
    bn::sprite_text_generator text_gen(common::fixed_8x8_sprite_font);
    bn::vector<bn::sprite_ptr, 128> text_sprites;
    bn::vector<bn::sprite_ptr, 1> empty;

    // ================= SETTING UP INITIAL VALUES AND STATES =================
    text_gen.set_center_alignment();

    while(true)
    {
        bn::core::update();
        connie.update();

        text_sprites = empty;
        text_gen.generate(0, 
            60, 
            bn::string<64>("X: ") + bn::to_string<64>(connie.getPosX().integer())
            + " " +
            bn::string<64>("Y: ") + bn::to_string<64>(connie.getPosY().integer())
            + " " +
            bn::string<64>("ID: ") + bn::to_string<64>(_map.bg_index),
            text_sprites);

        // text_gen.generate(0, 
        //     40, 
        //     bn::to_string<64>(_map.lvl_name),
        //     text_sprites);
    }
}
