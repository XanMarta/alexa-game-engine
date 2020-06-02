#include "CollisionObject.h"
#include "RenderPack.h"

bool show_collision = true;


void CollisionObject::set_collision_shape(CollisionShape* shape)
{
    this->shape = shape;
    shape->object = this;
}

void CollisionObject::check_collide(bool is_collide)
{
    if (is_collide)
    {
        if (!is_colliding) emit_signal("on_just_collision");
        is_colliding = true;
    }
    else
    {
        if (is_colliding) emit_signal("on_just_not_collision");
        is_colliding = false;
    }
}


// ==============================================================

void CollisionShape::_physics_process()
{
    update_collision(this);
    if (show_collision)
    {
        update_render_collision(get_position(), _size);
    }
}

// ==============================================================

void CollisionPack::reset()
{
    direct = Vector2().ZERO;
    distance = Vector2().ZERO;
    object = NULL;
    is_collision = false;
}
