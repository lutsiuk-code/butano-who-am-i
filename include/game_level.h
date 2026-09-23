#pragma once
#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include "bn_string.h"
#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "bn_regular_bg_tiles_item.h"
#include "bn_bg_palette_item.h"

#include "bn_regular_bg_items_connie_house.h"

#include "map_ids.h"

class map {
    public:
        map(bn::regular_bg_item level);

        bn::regular_bg_item curr_map;

        // bn::string<128> lvl_name;
        int bg_index;

        bn::regular_bg_ptr bg_ptr;
        bn::regular_bg_map_item map_item;

        void change_lvl(int next_lvl_index);

};

#endif