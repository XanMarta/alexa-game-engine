#ifndef NODE_BASE_H_INCLUDED
#define NODE_BASE_H_INCLUDED

#include "Vector2.h"
#include "signal.h"


class Node_Base
{
    public:

        virtual ~Node_Base() {}

        virtual void ready() = 0;
        virtual void process() = 0;
        virtual void physics_process() = 0;
        virtual void enter_tree() = 0;
        virtual void exit_tree() = 0;

        virtual void _enter_tree() {}

    protected:

        virtual void _ready() {}
        virtual void _process() {}
        virtual void _physics_process() {}
        virtual void _exit_tree() {}

};

#endif // NODE_BASE_H_INCLUDED
