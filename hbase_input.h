#ifndef HBASE_INPUT_H_INCLUDED
#define HBASE_INPUT_H_INCLUDED

#include "hbase.h"


class baseinput_pack
{
    public:

        bool is_on_pressed();
        bool is_just_pressed();
        bool is_just_released();

    protected:

        void _update(bool on_press);

        bool on_pressed = false;
        bool just_pressed = false;
        bool just_released = false;
};

#endif // HBASE_INPUT_H_INCLUDED
