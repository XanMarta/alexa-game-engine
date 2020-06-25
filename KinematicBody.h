#ifndef KINEMATICBODY_H_INCLUDED
#define KINEMATICBODY_H_INCLUDED

#include "CollisionObject.h"


class KinematicBody : public CollisionObject
{
    public:

        Vector2 move_and_collide(const Vector2& velocity);
        Vector2 move_and_slide(const Vector2& velocity);        // Slide with static_body

};

#endif // KINEMATICBODY_H_INCLUDED
