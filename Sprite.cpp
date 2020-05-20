#include "Sprite.h"


void Sprite::render()
{
    image_data[image].render(position, scale);
}
