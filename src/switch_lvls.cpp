#include "switch_lvls.h"
#include "map_ids.h"

int get_next_lvl(int& curr_level, bn::point plr_pos) {
    int return_val;

    switch(curr_level) {
        case game_levels::connie_house::connie_house_room:
            return_val = game_levels::connie_house::connie_house_hallway;
            break;
        case game_levels::connie_house::connie_house_hallway:
            if (plr_pos.x() <= 5 && plr_pos.x() >= -5) {
                return_val = game_levels::connie_house::connie_house_room;
            }
            break;
    }

    return return_val;
}
