#ifndef HCAMERA_H_INCLUDED
#define HCAMERA_H_INCLUDED

#include "hbase.h"
#include "hwindow.h"


class CameraPack
{
    public:

        Vector2 position = Vector2().ZERO;
        Vector2 zoom = Vector2().ONE;

        Vector2 _size = Vector2(SCREEN_WIDTH, SCREEN_HEIGHT);
};


#endif // HCAMERA_H_INCLUDED
