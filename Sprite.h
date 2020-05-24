#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include "CanvasItem.h"
#include "dimage.h"


class Sprite : public CanvasItem
{
    public:

        image_type image;


        void fix_to_size(Vector2 new_size);

        void _physics_process();


    private:

        void render();

};

#endif // SPRITE_H_INCLUDED
