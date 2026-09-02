#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include "bn_string.h"
#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_item.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_room.h"

class map {
    public:
        map();

        bn::string<32> map_id;
        bn::regular_bg_item curr_map;
        bn::regular_bg_ptr map_ptr;
        bn::regular_bg_map_item map_item;

        void change_lvl(bn::regular_bg_item level);

};

#endif