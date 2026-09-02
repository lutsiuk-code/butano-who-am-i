#include "collision_check.h"

constexpr int TILE_SIZE = 8;
constexpr int PLAYER_HITBOX_W = 6;
constexpr int PLAYER_HITBOX_H = 6;

bool is_wall(int tile_index) {
    return tile_index == 0 || tile_index == 5 || tile_index == 9 || tile_index == 38;
}

bool is_door(int tile_index) {
    return tile_index == 33;
}

bool is_solid_at(map& level, bn::fixed world_x, bn::fixed world_y) {
    auto dim = level.map_item.dimensions(); // map size in 8x8 tiles

    int map_w_px = dim.width() * TILE_SIZE;
    int map_h_px = dim.height() * TILE_SIZE;

    int px = world_x.integer() + map_w_px / 2;
    int py = world_y.integer() + map_h_px / 2;

    if (px < 0 || py < 0 || px >= map_w_px || py >= map_h_px)
    {
        return true;
    }

    bn::regular_bg_map_cell cell = level.map_item.cell(px / TILE_SIZE, py / TILE_SIZE);
    int tile_index = bn::regular_bg_map_cell_info(cell).tile_index();

    return is_wall(tile_index);
}

bool is_door_at(map& level, bn::fixed world_x, bn::fixed world_y) {
    auto dim = level.map_item.dimensions(); // map size in 8x8 tiles

    int map_w_px = dim.width() * TILE_SIZE;
    int map_h_px = dim.height() * TILE_SIZE;

    int px = world_x.integer() + map_w_px / 2;
    int py = world_y.integer() + map_h_px / 2;

    bn::regular_bg_map_cell cell = level.map_item.cell(px / TILE_SIZE, py / TILE_SIZE);
    int tile_index = bn::regular_bg_map_cell_info(cell).tile_index();

    return is_door(tile_index);
}

bool can_move_to(map& level, bn::fixed x, bn::fixed y)
{
    return !is_solid_at(level, x - PLAYER_HITBOX_W, y - PLAYER_HITBOX_H)
        && !is_solid_at(level, x + PLAYER_HITBOX_W, y - PLAYER_HITBOX_H)
        && !is_solid_at(level, x - PLAYER_HITBOX_W, y + PLAYER_HITBOX_H)
        && !is_solid_at(level, x + PLAYER_HITBOX_W, y + PLAYER_HITBOX_H);
}