#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include "Node.h"
#include "dimage.h"


class Sprite : public Node
{
    public:

        image_type image;
        bool is_showing = true;


        void render();

        void _physics_process();


    private:



};

#endif // SPRITE_H_INCLUDED
