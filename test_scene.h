#ifndef TEST_SCENE_H_INCLUDED
#define TEST_SCENE_H_INCLUDED

#include "Scene.h"
#include "Sprite.h"

class test_scene_root : public Node
{
    public:

        Node* player;
            Sprite* sprite1;
            Sprite* sprite2;



        void _physics_process();

        void setup();
};



class test_scene : public Scene
{
    public:

        void setup();
};


#endif // TEST_SCENE_H_INCLUDED
