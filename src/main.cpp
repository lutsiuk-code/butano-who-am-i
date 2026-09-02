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
    map _map(bn::regular_bg_items::room);

    // Create player object
    player connie(_map);

    // Assing camera to background
    _map.map_ptr.set_camera(connie.cameraPtr);

    // Create text generator instance
    bn::sprite_text_generator text_gen(common::fixed_8x8_sprite_font);
    bn::vector<bn::sprite_ptr, 32> text_sprites;
    bn::vector<bn::sprite_ptr, 32> empty;

    // ================= SETTING UP INITIAL VALUES AND STATES =================
    text_gen.set_center_alignment();

    while(true)
    {
        bn::core::update();
        connie.update();

        text_sprites = empty;
        text_gen.generate(0, 
            60, 
            bn::string<32>("X: ") + bn::to_string<32>(connie.getPosX().integer())
            + " " +
            bn::string<32>("Y: ") + bn::to_string<32>(connie.getPosY().integer())
            + " " +
            bn::to_string<32>(is_door_at(_map, connie.getPosX(), connie.getPosY())),
            text_sprites);
    }
}
