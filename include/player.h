#ifndef PLAYER_H
#define PLAYER_H

#include "bn_sprite_ptr.h"
#include "bn_sprite_item.h"
#include "bn_fixed.h"
#include "bn_camera_actions.h"
#include "bn_sprite_animate_actions.h"
#include "bn_point.h"
#include "game_level.h"

class player {
    private:
        bn::sprite_item sprite;
        bn::sprite_ptr spritePtr;

        // bn::point plrPos;

        enum class direction {FORWARD, LEFT, RIGHT, BACK, IDLE};
        direction current_dir;

        bn::sprite_animate_action<4> anim_action;

        map& level_info;

        void change_direction(direction dir);

    public:
        player(map& map_obj);

        bn::camera_ptr cameraPtr;

        bn::fixed getPosX();
        bn::fixed getPosY();
        bn::fixed getCamX();
        bn::fixed getCamY();

        bool isMoving;

        void setPosX(bn::fixed value);
        void setPosY(bn::fixed value);
        void setCamX(bn::fixed value);
        void setCamY(bn::fixed value);

        void update();
};

#endif