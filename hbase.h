#ifndef HBASE_H_INCLUDED
#define HBASE_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Vector2.h"

using namespace std;



extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern SDL_Event event;
extern const Uint8* currentKey;


// =================================================

void init_base();


// ============================== ASSISTANT FUNCTION

int random(int MIN, int MAX);


#endif // HBASE_H_INCLUDED
