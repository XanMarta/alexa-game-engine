#ifndef HCAMERA_H_INCLUDED
#define HCAMERA_H_INCLUDED

#include "hbase.h"
#include "hwindow.h"


extern Vector2 default_camera_position;
extern Vector2 default_camera_zoom;


class CameraPack
{
    public:

        Vector2* position = &default_camera_position;
        Vector2* zoom = &default_camera_zoom;


        void set_camera(Vector2* position, Vector2* zoom);
        void set_default();

        Vector2 _size = Vector2(SCREEN_WIDTH, SCREEN_HEIGHT);
};


#endif // HCAMERA_H_INCLUDED
