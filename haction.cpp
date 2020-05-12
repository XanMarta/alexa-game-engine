#include "haction.h"


key_pack key[TOTAL_KEY];
mouse_pack mouse;


// =============================================

bool action_pack::is_on_pressed()
{
    for (int i = 0; i < _key.size(); i++)
    {
        if (key[_key[i]].is_on_pressed()) return true;
    }
    if (_mouse)
    {
        if (mouse.is_on_pressed()) return true;
    }
    return false;
}

bool action_pack::is_just_pressed()
{
    for (int i = 0; i < _key.size(); i++)
    {
        if (key[_key[i]].is_just_pressed()) return true;
    }
    if (_mouse)
    {
        if (mouse.is_just_pressed()) return true;
    }
    return false;
}

bool action_pack::is_just_released()
{
    for (int i = 0; i < _key.size(); i++)
    {
        if (key[_key[i]].is_just_released()) return true;
    }
    if (_mouse)
    {
        if (mouse.is_just_released()) return true;
    }
    return false;
}
