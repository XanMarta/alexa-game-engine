#include "KinematicBody.h"


void KinematicBody::move_and_collide(const Vector2& velocity)
{
    if (!collision.is_collision)
    {
        position += velocity;
    }
    else
    {
        position -= collision.distance * collision.direct;
    }
}

void KinematicBody::move_and_slide(const Vector2& velocity)
{
    position += velocity;
    position -= collision.distance * collision.direct;
}
