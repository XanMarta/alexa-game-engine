#ifndef HWINDOW_H_INCLUDED
#define HWINDOW_H_INCLUDED

#include "hbase.h"

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;


bool init_window();

void set_camera(SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT});


#endif // HWINDOW_H_INCLUDED
