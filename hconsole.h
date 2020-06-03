#ifndef HCONSOLE_H_INCLUDED
#define HCONSOLE_H_INCLUDED

#include "hsdl.h"
#include "hwindow.h"
#include "himage.h"
#include "hinput.h"
#include "hcamera.h"


extern input_pack Input;
extern CameraPack Camera;


bool init_console();

void check_event();

bool is_exit_console();

void clear_console();

void show_image();

void close_console();


#endif // HCONSOLE_H_INCLUDED
