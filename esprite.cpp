#include "esprite.h"



void sprite::set_scale(Vector2 scale)
{
    this->scale = scale;
}

void sprite::render()
{
    image_data[image].render(position, scale);
}
