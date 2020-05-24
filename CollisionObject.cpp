#include "CollisionObject.h"
#include "himage.h"

bool show_collision = true;


void CollisionObject::set_collision_shape(CollisionShape* shape)
{
    this->shape = shape;
    shape->object = this;
}


// ==============================================================

void CollisionShape::_physics_process()
{
    update_collision(this);
    if (show_collision)
    {
        Vector2 pos = get_position();
        draw_rectangle({pos.x, pos.y, _size.x, _size.y});
    }
}
