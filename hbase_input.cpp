#include "hbase_input.h"


void baseinput_pack::_update(bool on_press)
{
    if (on_press)
    {
        just_pressed = !on_pressed;
        just_released = false;
    }
    else
    {
        just_released = on_pressed;
        just_pressed = false;
    }

    on_pressed = on_press;
}



bool baseinput_pack::is_on_pressed()
{
    return on_pressed;
}
bool baseinput_pack::is_just_pressed()
{
    return just_pressed;
}
bool baseinput_pack::is_just_released()
{
    return just_released;
}
