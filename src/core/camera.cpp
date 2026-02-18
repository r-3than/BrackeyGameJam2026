#include "core/camera.h"

camera_t *new_camera()
{
    camera_t *camera = (camera_t *)malloc(sizeof(camera_t));

    camera->position.x = 0.0f;
    camera->position.y = 0.0f;

    // in pixels
    camera->zoom.w = TILESHEET_ELEMENT_SIZE * 16;
    camera->zoom.h = TILESHEET_ELEMENT_SIZE * 12;

    return camera;
}

void delete_camera(camera_t *camera)
{
    free(camera);
}
