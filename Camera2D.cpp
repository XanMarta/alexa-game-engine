#include "Camera2D.h"


void Camera2D::set_camera(Vector2* anchor, Vector2 margin)
{
    this->anchor = anchor;
    this->margin = margin;
}

void Camera2D::set_default_camera()
{
    Camera.position = &global_position;
    Camera.zoom = &zoom;
    is_default = true;
}


void Camera2D::_physics_process()
{
    if (is_default)
    {
        // Calculate camera position
        Vector2 new_size = Camera._size / zoom;
        global_position = *anchor + margin - new_size / 2;
        global_position.x = clamp(global_position.x, limit_horizontal.x, limit_horizontal.y - new_size.x);
        global_position.y = clamp(global_position.y, limit_vertical.x, limit_vertical.y - new_size.y);
    }
}

void Camera2D::_exit_tree()
{
    if (is_default)
    {
        Camera.set_default();
    }
}
