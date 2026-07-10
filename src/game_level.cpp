#include "game_level.h"
#include "bn_fixed.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_regular_bg_items_room.h"
#include "bn_regular_bg_items_house_tiles.h"

map::map() :
    curr_map(bn::regular_bg_items::room),
    map_ptr(curr_map.create_bg()),
    map_item(curr_map.map_item())
{

}