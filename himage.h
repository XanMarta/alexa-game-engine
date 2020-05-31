#ifndef HIMAGE_H_INCLUDED
#define HIMAGE_H_INCLUDED

#include "hbase.h"



class image_pack
{
    public:

        image_pack();
        ~image_pack();


        bool flip_h = false;
        bool flip_v = false;
        double rotation = 0.0;


        bool load_image(string path);
        void render(const Vector2& position);
        void render(const Vector2& position, const Vector2& scale, const float& alpha);
        void render(const SDL_Rect& area);

        void set_flip(bool flip_h, bool flip_v);
        void set_size(Vector2 _size);

        Vector2 get_size();

    private:

        SDL_Texture* texture = NULL;
        Vector2 _size = {0, 0};

        SDL_RendererFlip flip = SDL_FLIP_NONE;
};

// =================================================

void draw_rectangle(SDL_Rect rect, SDL_Color color = {0xFF, 0xFF, 0xFF});
void clear_screen(SDL_Color color = {0xFF, 0xFF, 0xFF});

#endif // HIMAGE_H_INCLUDED
