#ifndef NODE_BASE_H_INCLUDED
#define NODE_BASE_H_INCLUDED

#include "Vector2.h"


class Node_Base
{
    public:

        virtual ~Node_Base() {}

        virtual void ready() = 0;
        virtual void process() = 0;

        Vector2 position = Vector2().ZERO;
        Vector2 scale = Vector2().ONE;

        virtual Vector2 get_position() = 0;
        virtual Vector2 get_scale() = 0;

    protected:

        virtual void _ready() {}
        virtual void _process() {}
        virtual void _physics_process() {}
};

#endif // NODE_BASE_H_INCLUDED
