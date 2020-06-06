#ifndef VISIBILITYNOTIFIER_H_INCLUDED
#define VISIBILITYNOTIFIER_H_INCLUDED

#include "Node.h"

/*
    Signal:
        screen_exit
        screen_enter
*/

class VisibilityNotifier : public Node
{
    public:

        Vector2 _size = Vector2(10, 10);

        bool is_on_screen();

        void _physics_process();

    private:

        bool on_screen = false;
};

#endif // VISIBILITYNOTIFIER_H_INCLUDED
