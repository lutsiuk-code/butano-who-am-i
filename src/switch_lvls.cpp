#include "switch_lvls.h"

constexpr entry_points entryPoints[] = {
    // From Connie's room to hallway
    {
        game_levels::connie_house::connie_house_room,               // Going from
        game_levels::connie_house::connie_house_hallway,            // Going to
        33,                                                         // Door tile X
        23,                                                         // Door tile Y
        15,                                                         // Spawn X
        45                                                          // Spawn Y
    },
    {
        game_levels::connie_house::connie_house_hallway,
        game_levels::connie_house::connie_house_room,
        34,
        38,
        15,
        -52
    }
};

bn::point world_to_tile(map& level, bn::fixed world_x, bn::fixed world_y) {
    auto dim = level.map_item.dimensions(); // in TILES, same for every room

    int map_w_px = dim.width() * 8;
    int map_h_px = dim.height() * 8;

    int px = world_x.integer() + map_w_px / 2;
    int py = world_y.integer() + map_h_px / 2;

    return bn::point(px / 8, py / 8);
}

bn::array<int, 4> get_next_lvl(map& level, int pX, int pY) {
    bn::array<int, 4> return_val;

    bn::point pos_in_tile = world_to_tile(level, pX, pY);

    for (int i = 0; i <= sizeof(entryPoints); i++) {
        if ((entryPoints[i].curr_map_index == level.bg_index) &&
            (entryPoints[i].tile_x == pos_in_tile.x()) &&
            (entryPoints[i].tile_y == pos_in_tile.y()))
        {
            return_val = {entryPoints[i].next_map_index, entryPoints[i].spawn_x, entryPoints[i].spawn_y};
            break;
        }
        else 
        {
            continue;
        }
    };

    // switch(curr_level) {
    //     case game_levels::connie_house::connie_house_room:
    //         return_val = {entryPoints[0].next_map_index, entryPoints[0].spawn_x, entryPoints[0].spawn_y};
    //         break;
    //     case game_levels::connie_house::connie_house_hallway:
    //         if (pX >= 33 && pX <= 35 && 
    //             pY >= 37 && pY <= 39)
    //         {
    //             return_val = {game_levels::connie_house::connie_house_room, 34, 36};
    //         }
    //         break;
    // }

    return return_val;
}
