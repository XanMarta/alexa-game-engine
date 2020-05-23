#ifndef TEST_SCENE_H_INCLUDED
#define TEST_SCENE_H_INCLUDED

#include "Scene.h"
#include "Sprite.h"

class test_scene_root : public Node
{
    public:

        Sprite sprite;


        void _ready();
        void _physics_process();
};

class test_scene : public Scene
{
    public:

        void setup();
};


#endif // TEST_SCENE_H_INCLUDED
