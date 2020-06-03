#include "hwindow.h"


int SCREEN_WIDTH = 720;
int SCREEN_HEIGHT = 720;

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
