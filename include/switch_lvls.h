#pragma once
#ifndef SWITCH_LVLS_H
#define SWITCH_LVLS_H

#include "entry_points.h"
#include "game_level.h"
#include "map_ids.h"

#include "bn_point.h"
#include "bn_fixed.h"
#include "bn_vector.h"
#include "bn_array.h"
#include "bn_list.h"

bn::point world_to_tile(map& level, bn::fixed world_x, bn::fixed world_y);
bn::array<int, 4> get_next_lvl(map& level, int pX, int pY);

#endif