#include "hkey.h"


void key_pack::set_key(SDL_Scancode keycode)
{
    this->keycode = keycode;
}

void key_pack::update()
{
    if (currentKey[keycode]) _update(true);
    else _update(false);
}
