#include "hcamera.h"


Vector2 default_camera_position = Vector2().ZERO;
Vector2 default_camera_zoom = Vector2().ONE;


void CameraPack::set_camera(Vector2* position, Vector2* zoom)
{
    this->position = position;
    this->zoom = zoom;
}
