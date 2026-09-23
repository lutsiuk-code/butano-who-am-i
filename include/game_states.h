#ifndef GAME_STATES_H
#define GAME_STATES_H

struct game_states {
    bool IN_MAIN_MENU;
    bool IN_GAME;
    bool PAUSED;
};

extern game_states* states;

#endif