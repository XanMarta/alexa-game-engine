#include "hinput.h"


void input_pack::init_input()
{
    key[KEY_A].set_key(SDL_SCANCODE_A);
    key[KEY_W].set_key(SDL_SCANCODE_W);
    key[KEY_S].set_key(SDL_SCANCODE_S);
    key[KEY_D].set_key(SDL_SCANCODE_D);
    key[KEY_P].set_key(SDL_SCANCODE_P);

    init_action();
}

void input_pack::update_input()
{
    for (int i = 0; i < TOTAL_KEY; i++)
    {
        key[i].update();
    }
    mouse.update();
}


void input_pack::init_action()
{
    action[MOVE_UP]._key.push_back(KEY_W);
    action[MOVE_UP]._key.push_back(KEY_UP);

    action[MOVE_LEFT]._key.push_back(KEY_A);
    action[MOVE_LEFT]._key.push_back(KEY_LEFT);

    action[MOVE_DOWN]._key.push_back(KEY_S);
    action[MOVE_DOWN]._key.push_back(KEY_DOWN);

    action[MOVE_RIGHT]._key.push_back(KEY_D);
    action[MOVE_UP]._key.push_back(KEY_RIGHT);

    action[BUTTON_CONSOLE]._key.push_back(KEY_P);

    action[MOUSE_C]._mouse = true;
}


bool input_pack::is_on_pressed(action_type type)
{
    return action[type].is_on_pressed();
}

bool input_pack::is_just_pressed(action_type type)
{
    return action[type].is_just_pressed();
}

bool input_pack::is_just_released(action_type type)
{
    return action[type].is_just_released();
}

int input_pack::get_action_length(action_type type)
{
    if (is_on_pressed(type)) return 1;
    else return 0;
}
