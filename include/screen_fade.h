#pragma once
#ifndef SCREEN_FADE_H
#define SCREEN_FADE_H

#include "bn_blending_actions.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_palettes.h"
#include "bn_bg_palettes_actions.h"
#include "bn_sprite_palettes_actions.h"
#include "bn_optional.h"
#include "bn_core.h"
#include "bn_colors.h"

void fade(int duration_in_frames, int final_value);

#endif