#include "hwindow.h"


bool init_window()
{
    gWindow = SDL_CreateWindow("Alexa", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
    {
        cout << "Could not create Window\n";
        return false;
    }
    return true;
}
