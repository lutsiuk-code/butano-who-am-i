#ifndef COLLISION_CHECK_H
#define COLLISION_CHECK_H

#include "bn_fixed.h"
// #include "bn_list.h"
#include "bn_point.h"
#include "game_level.h"
#include "bn_regular_bg_map_cell_info.h"

bool is_wall(int tile_index);
bool is_door(int tile_index);
bool is_solid_at(map& level, bn::fixed world_x, bn::fixed world_y);
bn::point is_door_at(map& level, bn::fixed world_x, bn::fixed world_y);
bool can_move_to(map& level, bn::fixed world_x, bn::fixed world_y);

// class colcheck {
//     private:
//         bool is_wall(int tile_index);
//         bool is_solid_at(map& level, bn::fixed world_x, bn::fixed world_y);
//     public:
//         bool can_move_to(map& level, bn::fixed world_x, bn::fixed world_y);
// };

#endif