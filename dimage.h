#ifndef DIMAGE_H_INCLUDED
#define DIMAGE_H_INCLUDED

#include "himage.h"


enum image_type
{
    BACKGROUND,
    TOTAL_IMAGE
};


extern image_pack image_data[TOTAL_IMAGE];


bool load_image();

#endif // DIMAGE_H_INCLUDED
