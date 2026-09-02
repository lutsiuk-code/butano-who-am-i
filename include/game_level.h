#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include "bn_string.h"
#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_item.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "bn_regular_bg_tiles_item.h"
#include "bn_bg_palette_item.h"

#include "bn_regular_bg_tiles_items_connie_house_tiles_32x32.h"
#include "bn_regular_bg_items_room.h"
#include "bn_regular_bg_items_hallway.h"

class map {
    public:
        map(bn::regular_bg_item level);

        // bn::string<32> map_id;
        bn::regular_bg_item curr_map;
        bn::regular_bg_tiles_item tiles;
        // bn::bg_palette_item pal_item;
        bn::regular_bg_map_item map_item;
        bn::regular_bg_ptr map_ptr;

        void change_lvl(bn::regular_bg_item level);

};

#endif