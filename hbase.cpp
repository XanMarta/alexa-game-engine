#include "hbase.h"


// =================================================

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Event event;
const Uint8* currentKey;


// =================================================

void init_base()
{
    srand(time(NULL));
}

// ============================== ASSISTANT FUNCTION

int random(int MIN, int MAX)
{
	return MIN + rand() % (MAX - MIN + 1);
}

float clamp(float value, float MIN, float MAX)
{
    if (value < MIN) return MIN;
    if (value > MAX) return MAX;
    return value;
}
