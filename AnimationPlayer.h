#ifndef ANIMATIONPLAYER_H_INCLUDED
#define ANIMATIONPLAYER_H_INCLUDED

#include <bits/stdc++.h>
#include "hsdl.h"
#include "Node.h"
#include "AnimationPack.h"
using namespace std;

/*
    Signal:
        animation_start
        animation_end
*/


class AnimationPlayer : public Node
{
    public:

        void add_animation(AnimationPack anim, string name);
        void set_animation(string name);

        void play(string name);

        void start();
        void pause();
        void stop();


        void _physics_process();

    private:

        vector<AnimationPack> animation;
        AnimationPack* current = NULL;
        bool is_running = false;

        uint32_t start_time;
        uint32_t pause_time;
        bool is_pause = false;

};


#endif // ANIMATIONPLAYER_H_INCLUDED
