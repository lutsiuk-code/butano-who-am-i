#ifndef CAMERA_H
#define CAMERA_H

#include "bn_camera_ptr.h"

struct cameraObj {
    const bn::camera_ptr camPtr = bn::camera_ptr::create();
};

extern cameraObj* camera;

#endif