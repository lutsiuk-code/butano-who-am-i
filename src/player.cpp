#include "player.h"
#include "bn_keypad.h"
#include "bn_span.h"
#include "bn_log.h"
#include "bn_point.h"
#include "bn_sprite_items_connie_sprites.h"
#include "collision_check.h"
#include "game_level.h"
#include "timer.h"
#include "screen_fade.h"

// GBA Buttons shortcuts
bn::keypad::key_type UP = bn::keypad::key_type::UP;
bn::keypad::key_type RIGHT = bn::keypad::key_type::RIGHT;
bn::keypad::key_type DOWN = bn::keypad::key_type::DOWN;
bn::keypad::key_type LEFT = bn::keypad::key_type::LEFT;


// Initialization list
player::player(map& map_obj) :
    sprite(bn::sprite_items::connie_sprites),
    spritePtr(sprite.create_sprite(0)),
    current_dir(direction::FORWARD),
    anim_action(bn::create_sprite_animate_action_forever(spritePtr, 10, sprite.tiles_item(), 0, 1, 2)),
    cameraPtr(bn::camera_ptr::create(spritePtr.x(), spritePtr.y())),
    level_info(map_obj)
{
    spritePtr.set_camera(cameraPtr);
}

// "Getters" for getting X and Y coordinates on screen
bn::fixed player::getPosX() {
    return spritePtr.x();
}

bn::fixed player::getPosY() {
    return spritePtr.y();
}

bn::fixed player::getCamX() {
    return cameraPtr.x();
}

bn::fixed player::getCamY() {
    return cameraPtr.y();
}

// Functions to set X or Y coordinates via sprite_ptr
void player::setPosX(bn::fixed value) {
    spritePtr.set_x(value);
}

void player::setPosY(bn::fixed value) {
    spritePtr.set_y(value);
}

void player::setCamX(bn::fixed value) {
    cameraPtr.set_x(value);
}

void player::setCamY(bn::fixed value) {
    cameraPtr.set_y(value);
}

void player::change_direction(direction dir) {
    if (current_dir == dir) {
        return;
    }

    current_dir = dir;

    if (current_dir == direction::FORWARD) {
        anim_action = bn::create_sprite_animate_action_forever(spritePtr, 10, sprite.tiles_item(), 0, 1, 2, 1);
    } else if (current_dir == direction::LEFT) {
        anim_action = bn::create_sprite_animate_action_forever(spritePtr, 10, sprite.tiles_item(), 3, 4, 5, 4);
    } else if (current_dir == direction::RIGHT) {
        anim_action = bn::create_sprite_animate_action_forever(spritePtr, 10, sprite.tiles_item(), 3, 4, 5, 4);
    } else if (current_dir == direction::BACK) {
        anim_action = bn::create_sprite_animate_action_forever(spritePtr, 10, sprite.tiles_item(), 6, 7, 8, 7);
    }
}

// Update handler
void player::update() {
    // Player movement

    if (bn::keypad::held(UP) && can_move_to(level_info, getPosX(), getPosY() - 4)) {
        setPosY(getPosY() - 1);
        change_direction(direction::BACK);
        isMoving = true;
    } else if (bn::keypad::held(DOWN) && can_move_to(level_info, getPosX(), getPosY() + 4)) {
        setPosY(getPosY() + 1);
        change_direction(direction::FORWARD);
        isMoving = true;
    } else if (bn::keypad::held(RIGHT) && can_move_to(level_info, getPosX() + 4, getPosY())) {
        setPosX(getPosX() + 1);
        change_direction(direction::RIGHT);
        isMoving = true;
    } else if (bn::keypad::held(LEFT) && can_move_to(level_info, getPosX() - 4, getPosY())) {
        setPosX(getPosX() - 1);
        change_direction(direction::LEFT);
        isMoving = true;
    } else {
        isMoving = false;
    }

    if (current_dir == direction::RIGHT) {
        spritePtr.set_horizontal_flip(true);
    } else {
        spritePtr.set_horizontal_flip(false);
    }

    if (isMoving) {
        anim_action.update();
    } else {
        anim_action.set_current_index(1);
    }

    // is_door_at(level_info, getPosX(), getPosY());

    bn::point debug_tile = world_to_tile(level_info, getPosX(), getPosY());
    BN_LOG(debug_tile.x(), " ", debug_tile.y());

    if(is_door_at(level_info, getPosX(), getPosY())) {
        fade(60, 1);

        // timer(60);

        bn::array<int,4> next_lvl_info = get_next_lvl(level_info, getPosX().integer(), getPosY().integer());
        level_info.change_lvl(next_lvl_info[0]);
        level_info.bg_ptr.set_camera(cameraPtr);

        setPosX(next_lvl_info[1]);
        setCamX(getPosX());
        setPosY(next_lvl_info[2]);
        setCamY(getPosY());

        timer(60);

        fade(60, 0);
    }

    setCamY(getPosY());
    setCamX(getPosX());
}