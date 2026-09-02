#include "game_level.h"

map::map() :
    map_id("connie_room"),
    curr_map(bn::regular_bg_items::room),
    map_ptr(curr_map.create_bg()),
    map_item(curr_map.map_item())
{

}

void map::change_lvl(bn::regular_bg_item level) {
    curr_map = level;
    map_ptr = curr_map.create_bg();
    map_item = curr_map.map_item();
}