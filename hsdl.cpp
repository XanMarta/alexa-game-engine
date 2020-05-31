#include "hsdl.h"


bool init_SDL()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        cout << "Could not init SDL\n";
        return false;
    }
    else
    {
        if (!init_window()) return false;
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL)
            {
                cout << "Could not create Renderer\n";
                return false;
            }
            else
            {
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    cout << "Could not init SDL image\n";
                    return false;
                }
                else return true;
            }
        }
    }
}

uint32_t get_time()
{
    return SDL_GetTicks();
}


