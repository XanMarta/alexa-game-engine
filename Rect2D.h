#ifndef RECT2D_H_INCLUDED
#define RECT2D_H_INCLUDED

#include "Vector2.h"


struct Rect2D
{
    Rect2D(const Vector2& position, const Vector2& _size);

    Vector2 position;
    Vector2 _size;

    bool is_collision_with(const Rect2D& rect);
    bool is_inside(const Rect2D& rect);
    bool is_on_sight(const Rect2D& rect);
};


#endif // RECT2D_H_INCLUDED
