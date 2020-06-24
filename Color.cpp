#include "Color.h"


color_modulation::color_modulation(float r, float g, float b, float a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

SDL_Color color_modulation::to_SDL_Color()
{
    return SDL_Color({r, g, b, a});
}
