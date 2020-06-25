#include "KinematicBody.h"


Vector2 KinematicBody::move_and_collide(const Vector2& velocity)
{
    Vector2 new_velocity = velocity;
    if (collision.is_collision)
    {
        if (collision.object->is_static_body)
        {
            new_velocity = Vector2().ZERO;
        }
    }

    position += new_velocity;
    return new_velocity;
}

Vector2 KinematicBody::move_and_slide(const Vector2& velocity)
{
    Vector2 new_velocity = velocity;
    if (collision.is_collision)
    {
        if (collision.object->is_static_body)
        {
            position -= collision.distance * collision.direct;
            Vector2 new_direct = Vector2().ONE;
            if (velocity.x * collision.direct.x > 0) new_direct.x = 0.0;
            if (velocity.y * collision.direct.y > 0) new_direct.y = 0.0;
            new_velocity = new_direct * velocity;
        }
    }

    position += new_velocity;
    return new_velocity;
}
