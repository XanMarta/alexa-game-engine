#include "himage.h"

// =================================================
SDL_Texture* loadImageTexture(string path);

// =================================================

image_pack::image_pack()
{

}

image_pack::~image_pack()
{
    SDL_DestroyTexture(texture);
    texture = NULL;
}

bool image_pack::load_image(string path)
{
    texture = loadImageTexture(path);
    if (texture != NULL)
    {
        int w, h;
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);
        _size = Vector2(w, h);
        return true;
    }
    else return false;
}

void image_pack::render(Vector2& position)
{
    SDL_Rect rect = {position.x, position.y, _size.x, _size.y};
    SDL_RenderCopyEx(gRenderer, texture, NULL, &rect, rotation, NULL, flip);
}

void image_pack::render(Vector2& position, Vector2& scale)
{
    SDL_Rect rect = {position.x, position.y, _size.x * scale.x, _size.y * scale.y};
    SDL_RenderCopyEx(gRenderer, texture, NULL, &rect, rotation, NULL, flip);
}

void image_pack::render(SDL_Rect& area)
{
    SDL_RenderCopyEx(gRenderer, texture, NULL, &area, rotation, NULL, flip);
}

void image_pack::set_flip(bool flip_h, bool flip_v)
{
    flip = SDL_FLIP_NONE;
    if (flip_h && flip_v) rotation = 180.0;
    else if (flip_h) flip = SDL_FLIP_HORIZONTAL;
    else if (flip_v) flip = SDL_FLIP_VERTICAL;
}

void image_pack::set_size(Vector2 _size)
{
    this->_size = _size;
}

Vector2 image_pack::get_size()
{
    return _size;
}

// =================================================

void draw_rectangle(SDL_Rect rect, SDL_Color color)
{
    SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(gRenderer, &rect);
}

void clear_screen(SDL_Color color)
{
    SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(gRenderer);
}

// =================================================

// Load PNG file
SDL_Texture* loadImageTexture(string path)
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = NULL;
    loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        cout << "Could not load image " << path << endl;
    }
    newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    if (newTexture == NULL)
    {
        cout << "Could not create Texture from " << path << endl;
    }
    SDL_FreeSurface(loadedSurface);
    return newTexture;
}


