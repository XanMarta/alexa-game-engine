#ifndef COLLISIONOBJECT_H_INCLUDED
#define COLLISIONOBJECT_H_INCLUDED

#include "CanvasItem.h"
#include "CollisionBase.h"

/*
    CollisionObject
        object to check to collision with another object
        Need CollisionShape as its child

    Signal:
        on_just_collision
        on_just_not_collision

*/

class CollisionShape;
class CollisionObject;

// =======================================================
// Detail of collision
class CollisionPack
{
    public:

        Vector2 direct = Vector2().ZERO;
        Vector2 distance = Vector2().ZERO;
        CollisionObject* object = NULL;
        bool is_collision = false;


        void reset();

};

// =======================================================

class CollisionObject : public CanvasItem
{
    public:

        CollisionShape* shape;

        CollisionPack collision;



        void set_collision_shape(CollisionShape* shape);    // Must be called on ready


        void check_collide(bool is_collide);

    private:

        bool is_colliding = false;

};

// =======================================================

class CollisionShape : public Node
{
    public:

        vector<Collision_Layer> layer;
        vector<Collision_Layer> mask;

        Vector2 _size = Vector2().ZERO;


        CollisionObject* object;

        void _physics_process();
};



// =======================================================

void update_collision(CollisionShape* shape);   // Declaration on CollisionBase.cpp

#endif // COLLISIONOBJECT_H_INCLUDED
