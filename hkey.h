#ifndef HKEY_H_INCLUDED
#define HKEY_H_INCLUDED

#include "hbase_input.h"

class key_pack : public baseinput_pack
{
    public:

        void set_key(SDL_Scancode keycode);

        void update();

    private:

        SDL_Scancode keycode;

};


#endif // HKEY_H_INCLUDED
