#include "dimage.h"


image_pack image_data[TOTAL_IMAGE];


bool load_image()
{
    bool success = true;

    if (!image_data[BACKGROUND].load_image("image/background.png")) success = false;
    if (!image_data[COIN].load_image("image/coin.png")) success = false;

    return success;
}
