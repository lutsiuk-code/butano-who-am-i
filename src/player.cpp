#include "player.h"
#include "bn_keypad.h"
#include "bn_span.h"
#include "bn_log.h"
#include "bn_point.h"
#include "bn_sprite_items_connie_sprites.h"
#include "collision_check.h"
#include "game_level.h"

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

    if(is_door_at(level_info, getPosX(), getPosY())) {
        level_info.change_lvl(bn::regular_bg_items::connie_house, bn::point(getPosX().integer(), getPosY().integer()));
        level_info.bg_ptr.set_camera(cameraPtr);

        setPosX(0);
        setPosY(0);
    }

    // BN_LOG("X: ", getPosX().integer(), " Y: ", getPosY().integer(), " TILE: ", bn::regular_bg_map_cell_info(level_info.map_item.cell(getPosX().integer(), getPosY().integer())).tile_index());

    // bn::fixed playerX = ((playerPos.x() * 2) - 128)/2;
    // bn::fixed playerY = ((playerPos.y() * 2) - 128)/2;

    // setPosX(playerX);
    // setPosY(playerY);

    // if (getPosY().integer() < getCamY().integer() - 20 && isMoving ) {
        // setCamY(getCamY() - 1);
    // }

    setCamY(getPosY());
    setCamX(getPosX());

    // Debug info
    // BN_LOG("X: ", getPosX(), " Y: ", getPosY());
    // BN_LOG("CAM X: ", getCamX(), " CAM Y: ", getCamY().integer());
}