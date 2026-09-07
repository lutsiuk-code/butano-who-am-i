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

void map::change_lvl(bn::regular_bg_item level, bn::point plr_pos) {
    // map::curr_map = level;
    map::bg_index = get_next_lvl(map::bg_index, plr_pos);
    map::bg_ptr = curr_map.create_bg(map::bg_index);
}