#include "bn_core.h"
#include "bn_point.h"
#include "bn_log.h"

// #include "camera.h"
#include "player.h"
#include "game_level.h"

#include "bn_regular_bg_map_cell_info.h"

int main()
{
    bn::core::init();

    BN_LOG("GAME INIT. HELLO, WORLD!");

    // Create map object
    map _map;

    int mapWidth = _map.map_item.dimensions().width();
    int mapHeight = _map.map_item.dimensions().height();

    // Create player object
    player connie(_map);

    // Assing camera to background
    _map.map_ptr.set_camera(connie.cameraPtr);

    while(true)
    {
        bn::core::update();
        connie.update();
    }
}
