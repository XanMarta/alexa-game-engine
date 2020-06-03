#ifndef TEST_SCENE_H_INCLUDED
#define TEST_SCENE_H_INCLUDED

#include "Scene.h"
#include "Sprite.h"
#include "CollisionObject.h"
#include "KinematicBody.h"
#include "AnimationPlayer.h"
#include "Timer.h"


class test_scene_2 : public Node
{
    public:

        void _physics_process();
        void execute_signal(string signal_name);
        void boom()
        {
            cout << "Boom\n";
        }

};

class test_scene_root : public Node
{
    public:

        Sprite* backg;
        Node* character;
            KinematicBody* player;
                CollisionShape* player_collision;
                Sprite* sprite1;
        CollisionObject* ball;
            CollisionShape* ball_collision;
            Sprite* wal;
        test_scene_2* test;
        AnimationPlayer* animate;
        Timer* timer;


        void _ready();
        void _physics_process();

        void execute_signal(string signal_name);

        void go();
        void dance();
        void stop();

        void setup();
};



class test_scene : public Scene
{
    public:

        void setup();
};


#endif // TEST_SCENE_H_INCLUDED
