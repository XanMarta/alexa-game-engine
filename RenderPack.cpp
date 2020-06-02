#include "RenderPack.h"


RenderLayerPack _layer[RENDER_LAYER_MAX + 5];

vector<RenderCollisionPack> collision_render;


RenderPack::RenderPack(const image_type& type, const Vector2& position, const Vector2& scale)
{
    this->type = type;
    this->position = position;
    this->scale = scale;
}

void RenderPack::render()
{
    image_data[type].render(position, scale);
}

// ==================================================================================

void RenderLayerPack::update(const image_type& type, const Vector2& position, const Vector2& scale)
{
    pack.push_back(RenderPack(type, position, scale));
}

void RenderLayerPack::render()
{
    for (int i = 0; i < pack.size(); i++)
    {
        pack[i].render();
    }
}

// ==================================================================================

RenderCollisionPack::RenderCollisionPack(const Vector2& position, const Vector2& _size)
{
    this->position = position;
    this->_size = _size;
}

void RenderCollisionPack::render()
{
    draw_rectangle({position.x, position.y, _size.x, _size.y}, {0x00, 0x00, 0xFF}, 50.0);
}

// ==================================================================================

void update_render(int layer, const image_type& type, const Vector2& position, const Vector2& scale)
{
    _layer[layer].update(type, position, scale);
}

void update_render_collision(const Vector2& position, const Vector2& _size)
{
    collision_render.push_back(RenderCollisionPack(position, _size));
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
