#ifndef HINPUT_H_INCLUDED
#define HINPUT_H_INCLUDED

#include "haction.h"


enum action_type
{
    MOVE_UP, MOVE_LEFT, MOVE_DOWN, MOVE_RIGHT,
    MOUSE_C,
    TOTAL_ACTION
};


class input_pack
{
    public:

        void init_input();
        void update_input();



        bool is_on_pressed(action_type type);
        bool is_just_pressed(action_type type);
        bool is_just_released(action_type type);

        int get_action_length(action_type type);

    private:

        void init_action();

        action_pack action[TOTAL_ACTION];
};




#endif // HINPUT_H_INCLUDED
