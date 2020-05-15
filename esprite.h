#ifndef ESPRITE_H_INCLUDED
#define ESPRITE_H_INCLUDED


#include "dimage.h"


class sprite
{
    public:

        image_type image;


        void render();
        void set_scale(Vector2 scale);


    private:

        Vector2 position = {0, 0};
        Vector2 scale = {1.0, 1.0};

};


#endif // ESPRITE_H_INCLUDED
