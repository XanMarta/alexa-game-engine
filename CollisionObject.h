#ifndef COLLISIONOBJECT_H_INCLUDED
#define COLLISIONOBJECT_H_INCLUDED

#include "CanvasItem.h"
#include "CollisionBase.h"


class CollisionShape;

class CollisionObject : public CanvasItem
{
    public:

        CollisionShape* shape;


        void set_collision_shape(CollisionShape* shape);


        virtual void on_collision() {}
        virtual void on_just_collision() {}
        virtual void on_not_collision() {}
        virtual void on_just_not_collision() {}



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
