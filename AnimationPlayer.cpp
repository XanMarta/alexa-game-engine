#include "AnimationPlayer.h"


void AnimationPlayer::add_animation(AnimationPack anim, string name)
{
    anim.name = name;
    animation.push_back(anim);
}

void AnimationPlayer::set_animation(string name)
{
    current = NULL;
    for (int i = 0; i < animation.size(); i++)
    {
        if (animation[i].name == name)
        {
            current = &animation[i];
            return;
        }
    }
}

void AnimationPlayer::start()
{
    if (is_pause) start_time = get_time() - pause_time;
    else start_time = get_time();

    is_running = true;
    is_pause = false;
    emit_signal("animation_start");
}

void AnimationPlayer::pause()
{
    if (!is_pause)
    {
        pause_time = get_time() - start_time;
        is_pause = true;
        is_running = false;
    }
}

void AnimationPlayer::stop()
{
    is_running = false;
    is_pause = false;
    emit_signal("animation_end");
}


void AnimationPlayer::_physics_process()
{
    if (is_running)
    {
        if (current != NULL)
        {
            float time = (get_time() - start_time) / 1000.0;
            current->update(time);

            if (current->is_end)
            {
                current->is_end = false;
                stop();
            }
        }
    }
}
