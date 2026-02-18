#ifndef CAMERA_H
#define CAMERA_H

#include <cstdlib>

#define TILESHEET_ELEMENT_SIZE 32

typedef struct camera {
    struct {
        float x;
        float y;
    } position;
    struct {
        float w;
        float h;
    } zoom;
} camera_t;

camera_t *new_camera();
void delete_camera(camera_t *camera);

#endif
