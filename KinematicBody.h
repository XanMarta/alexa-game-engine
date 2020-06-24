#ifndef KINEMATICBODY_H_INCLUDED
#define KINEMATICBODY_H_INCLUDED

#include "CollisionObject.h"


class KinematicBody : public CollisionObject
{
    public:

        void move_and_collide(const Vector2& velocity);
        Vector2 move_and_slide(const Vector2& velocity);

};

#endif // KINEMATICBODY_H_INCLUDED
