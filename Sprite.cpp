#include "Sprite.h"


void Sprite::render()
{
    image_data[image].render(position, scale);
}

void Sprite::_physics_process()
{
    if (is_showing) render();
}
