#include "ddata.h"


bool load_data()
{
    bool success = true;

    if (!load_image()) success = false;

    return success;
}
