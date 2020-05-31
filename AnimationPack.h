#ifndef ANIMATIONPACK_H_INCLUDED
#define ANIMATIONPACK_H_INCLUDED


#include <bits/stdc++.h>
#include <vector>
#include "Bone1D.h"
using namespace std;



struct AnimationTrack
{
    Bone1D bone;
    float* variable;
    string name = "";

    void add_node(float time, float data);
    // Add in the order of time. Must add node with time = 0 first

    void update_data(float time);

};


struct AnimationPack
{
    string name = "";
    vector<AnimationTrack> track;

    float length = 1.0;
    bool repeat = false;


    void add_track(AnimationTrack new_track);

    void update(float time);

    // Signal
    bool is_end = false;
};


#endif // ANIMATIONPACK_H_INCLUDED
