#include "Sprite.h"


void Sprite::fix_to_size(Vector2 new_size)
{
    scale = new_size / image_data[image].get_size();
}

void Sprite::_physics_process()
{
    if (is_showing) update_render(layer, image, get_global_position(), get_global_scale(), get_global_modulation().to_SDL_Color());
}
