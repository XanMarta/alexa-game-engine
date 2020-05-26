#ifndef TEST_SCENE_H_INCLUDED
#define TEST_SCENE_H_INCLUDED

#include "Scene.h"
#include "Sprite.h"
#include "CollisionObject.h"

class test_scene_root : public Node
{
    public:

        Sprite* backg;
        CollisionObject* player;
            CollisionShape* player_collision;
            Sprite* sprite1;
        CollisionObject* ball;
            CollisionShape* ball_collision;


        void _ready();
        void _physics_process();

        void setup();
};



class test_scene : public Scene
{
    public:

        void setup();
};


#endif // TEST_SCENE_H_INCLUDED
