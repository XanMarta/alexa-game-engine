#ifndef HBASE_H_INCLUDED
#define HBASE_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;



extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern SDL_Event event;
extern const Uint8* currentKey;


// =================================================

struct Vector2
{
    int x;
    int y;
};

struct Vector2F
{
    float x;
    float y;
};

// =================================================

void init_base();


// ============================== ASSISTANT FUNCTION

int random(int MIN, int MAX);


#endif // HBASE_H_INCLUDED
