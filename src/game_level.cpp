#include "game_level.h"

map::map(bn::regular_bg_item level) :
    curr_map(level),
    tiles(bn::regular_bg_tiles_items::connie_house_tiles_32x32),
    map_item(curr_map.map_item()),
    map_ptr(curr_map.create_bg())
{

}

void map::change_lvl(bn::regular_bg_item level) {
    map::curr_map = level;
    map::map_item = curr_map.map_item();
    map::map_ptr = curr_map.create_bg();
}