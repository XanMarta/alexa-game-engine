#ifndef RENDERPACK_H_INCLUDED
#define RENDERPACK_H_INCLUDED



#include "dimage.h"
#include "hconsole.h"



const int RENDER_LAYER_MAX = 20;


struct RenderPack
{
    RenderPack(const image_type& type, const Vector2& position, const Vector2& scale);

    image_type type;
    Vector2 position;
    Vector2 scale;

    void render();
};

struct RenderLayerPack
{
    vector<RenderPack> pack;

    void update(const image_type& type, const Vector2& position, const Vector2& scale);
    void render();
};

struct RenderCollisionPack
{
    RenderCollisionPack(const Vector2& position, const Vector2& _size);

    Vector2 position;
    Vector2 _size;

    void render();
};

// ==================================================================================

void update_render(int layer, const image_type& type, const Vector2& position, const Vector2& scale);
void update_render_collision(const Vector2& position, const Vector2& _size);


void show_render();

#endif // RENDERPACK_H_INCLUDED
