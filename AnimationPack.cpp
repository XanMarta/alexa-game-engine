#include "AnimationPack.h"


void AnimationTrack::add_node(float time, float data)
{
    bone.add_point(time, data);
}

void AnimationTrack::update_data(float time)
{
    *variable = bone.get_data_at(time);
}

// ===========================================================

void AnimationPack::add_track(AnimationTrack new_track)
{
    track.push_back(new_track);
}

void AnimationPack::update(float time)
{
    if (time > length)
    {
        if (repeat)
        {
            while (time > length) time -= length;
            for (int i = 0; i < track.size(); i++) track[i].update_data(time);
        }
        else
        {
            is_end = true;
        }
    }
    else
    {
        for (int i = 0; i < track.size(); i++) track[i].update_data(time);
    }
}
