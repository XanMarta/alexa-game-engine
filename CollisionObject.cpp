#include "CollisionObject.h"
#include "himage.h"

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
        Vector2 pos = get_position();
        draw_rectangle({pos.x, pos.y, _size.x, _size.y}, {0x00, 0x00, 0xFF});
    }
}
