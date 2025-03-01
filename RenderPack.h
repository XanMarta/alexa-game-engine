#ifndef RENDERPACK_H_INCLUDED
#define RENDERPACK_H_INCLUDED



#include "dimage.h"
#include "hconsole.h"



const int RENDER_LAYER_MAX = 20;


struct RenderPack
{
    RenderPack(const image_type& type, const Vector2& position, const Vector2& scale, const SDL_Color& modulation);

    image_type type;
    Vector2 position;
    Vector2 scale;
    SDL_Color modulation;

    void render();
};

struct RenderLayerPack
{
    vector<RenderPack> pack;

    void update(const image_type& type, const Vector2& position, const Vector2& scale, const SDL_Color& modulation);
    void render();
};

struct RenderCollisionPack
{
    RenderCollisionPack(const Vector2& position, const Vector2& _size, const SDL_Color& color);

    Vector2 position;
    Vector2 _size;
    SDL_Color color;

    void render();
};

// ==================================================================================

void update_render(int layer, const image_type& type, const Vector2& position, const Vector2& scale, const SDL_Color& modulation);
void update_render_collision(const Vector2& position, const Vector2& _size, SDL_Color = {0x00, 0x00, 0xFF});


void show_render();

#endif // RENDERPACK_H_INCLUDED
