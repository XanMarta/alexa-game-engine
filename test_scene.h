#ifndef TEST_SCENE_H_INCLUDED
#define TEST_SCENE_H_INCLUDED

#include "Scene.h"
#include "Sprite.h"

class test_scene_root : public Sprite
{
    public:

        void _ready();
        void _process();
        void _physics_process();
};

class test_scene : public Scene
{
    public:

        void setup();
};


#endif // TEST_SCENE_H_INCLUDED
