#include "hconsole.h"


input_pack Input;
CameraPack Camera;


bool init_console()
{
    if (!init_SDL()) return false;
    init_base();
    Input.init_input();
    return true;
}

void check_event()
{
    SDL_PollEvent(&event);
    currentKey = SDL_GetKeyboardState(NULL);
    Input.update_input();
}

bool is_exit_console()
{
    return event.type == SDL_QUIT;
}

void clear_console()
{
    clear_screen();
}

void show_image()
{
    SDL_RenderPresent(gRenderer);
}

void close_console()
{
    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    IMG_Quit();
    SDL_Quit();
}

