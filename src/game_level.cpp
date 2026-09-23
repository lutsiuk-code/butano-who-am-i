#include "game_level.h"
#include "switch_lvls.h"
#include "bn_log.h"

map::map(bn::regular_bg_item level) :
    curr_map(level),
    bg_index(game_levels::connie_house::connie_house_room),
    bg_ptr(curr_map.create_bg(bg_index)),
    map_item(curr_map.map_item())
    
{

}

void map::change_lvl(int next_lvl_index) {

    // bn::array<int, 4> next_lvl_info = get_next_lvl(map::bg_index, plr_pos.x(), plr_pos.y());
    // map::bg_index = next_lvl_info[0];


    // map::curr_map = level;
    map::bg_index = next_lvl_index;
    map::bg_ptr = curr_map.create_bg(map::bg_index);
}