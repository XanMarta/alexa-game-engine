#ifndef HACTION_H_INCLUDED
#define HACTION_H_INCLUDED

#include "hkey.h"
#include "hmouse.h"


enum key_type
{
    KEY_W, KEY_A, KEY_S, KEY_D,
    KEY_UP, KEY_LEFT, KEY_DOWN, KEY_RIGHT,
    TOTAL_KEY
};

extern key_pack key[TOTAL_KEY];
extern mouse_pack mouse;


// =============================================
// =============================================

class action_pack
{
    public:

        bool is_on_pressed();
        bool is_just_pressed();
        bool is_just_released();


        vector<key_type> _key;
        bool _mouse = false;

};




#endif // HACTION_H_INCLUDED
