#include "Rect2D.h"


Rect2D::Rect2D(const Vector2& position, const Vector2& _size)
{
    this->position = position;
    this->_size = _size;
}


bool Rect2D::is_collision_with(const Rect2D& rect)
{
    if (position.x + _size.x < rect.position.x) return false;
    if (position.y + _size.y < rect.position.y) return false;
    if (rect.position.x + rect._size.x < position.x) return false;
    if (rect.position.y + rect._size.y < position.y) return false;
    return true;
}

bool Rect2D::is_inside(const Rect2D& rect)
{
    if (position.x < rect.position.x) return false;
    if (position.y < rect.position.y) return false;
    if (position.x + _size.x > rect.position.x + rect._size.x) return false;
    if (position.y + _size.y > rect.position.y + rect._size.y) return false;
    return true;
}

bool Rect2D::is_on_sight(const Rect2D& rect)
{
    if (position.x + _size.x < rect.position.x) return false;
    if (position.y + _size.y < rect.position.y) return false;
    if (rect.position.x + rect._size.x < position.x) return false;
    if (rect.position.y + rect._size.y < position.y) return false;
    return true;
}
