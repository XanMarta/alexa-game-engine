#include "RenderPack.h"


RenderLayerPack _layer[RENDER_LAYER_MAX + 5];

vector<RenderCollisionPack> collision_render;


RenderPack::RenderPack(const image_type& type, const Vector2& position, const Vector2& scale, const SDL_Color& modulation)
{
    this->type = type;
    this->position = position;
    this->scale = scale;
    this->modulation = modulation;
}

void RenderPack::render()
{
    image_data[type].render((position - *Camera.position) * *Camera.zoom, scale * *Camera.zoom, modulation);
}

// ==================================================================================

void RenderLayerPack::update(const image_type& type, const Vector2& position, const Vector2& scale, const SDL_Color& modulation)
{
    pack.push_back(RenderPack(type, position, scale, modulation));
}

void RenderLayerPack::render()
{
    for (int i = 0; i < pack.size(); i++)
    {
        pack[i].render();
    }
}

// ==================================================================================

RenderCollisionPack::RenderCollisionPack(const Vector2& position, const Vector2& _size, const SDL_Color& color)
{
    this->position = position;
    this->_size = _size;
    this->color = color;
}

void RenderCollisionPack::render()
{
    Vector2 draw_pos = (position - *Camera.position) * *Camera.zoom;
    Vector2 draw_size = _size * *Camera.zoom;
    draw_rectangle({draw_pos.x, draw_pos.y, draw_size.x, draw_size.y}, color, 50.0);
}

// ==================================================================================

void update_render(int layer, const image_type& type, const Vector2& position, const Vector2& scale, const SDL_Color& modulation)
{
    _layer[layer].update(type, position, scale, modulation);
}

void update_render_collision(const Vector2& position, const Vector2& _size, SDL_Color color)
{
    collision_render.push_back(RenderCollisionPack(position, _size, color));
}



void show_render()
{
    for (int i = 0; i <= RENDER_LAYER_MAX; i++)
    {
        _layer[i].render();
        // Clear
        _layer[i].pack.clear();
    }
    for (int i = 0; i < collision_render.size(); i++)
    {
        collision_render[i].render();
    }
    collision_render.clear();
}
