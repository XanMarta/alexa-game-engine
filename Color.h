#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include "hbase.h"


struct color_modulation
{
    float r = 255.0;
    float g = 255.0;
    float b = 255.0;
    float a = 255.0;

    color_modulation() {}
    color_modulation(float r, float g, float b, float a);
    SDL_Color to_SDL_Color();
};


#endif // COLOR_H_INCLUDED
