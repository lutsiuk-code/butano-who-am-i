#include "timer.h"

void timer(int duration_in_seconds) {
    for (int i = 0; i <= duration_in_seconds; i++) {
        bn::core::update();
    }
}