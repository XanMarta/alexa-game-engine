#include "KinematicBody.h"


void KinematicBody::move_and_collide(const Vector2& velocity)
{
    if (!collision.is_collision)
    {
        position += velocity;
    }
    else
    {
        if (!collision.object->is_static_body) position += velocity;
        else position -= collision.distance * collision.direct;
    }
}

void KinematicBody::move_and_slide(const Vector2& velocity)
{
    position += velocity;
    if (collision.is_collision)
    {
        if (collision.object->is_static_body) position -= collision.distance * collision.direct;
    }
}
