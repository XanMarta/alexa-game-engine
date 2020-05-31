#include "test_scene.h"


void test_scene::setup()
{
    test_scene_root* _root = new test_scene_root();
    _root->setup();
    root = _root;
}

// ==============================================

void test_scene_root::setup()
{
    name = "Test root";

    backg = new Sprite();
    backg->name = "background";
    backg->image = BACKGROUND;
    backg->fix_to_size(Vector2(720, 720));
    add_child(backg);

    player = new KinematicBody();
    player->name = "Player";
    player->position = Vector2(20, 100);
    add_child(player);

        player_collision = new CollisionShape();
        player_collision->name = "player_collision";
        player_collision->layer.push_back(PLAYER);
        player_collision->mask.push_back(WALL);
        player_collision->_size = Vector2(65, 65);
        player->add_child(player_collision);
        player->set_collision_shape(player_collision);

        sprite1 = new Sprite();
        sprite1->name = "sprite1";
        sprite1->image = COIN;
        sprite1->scale = Vector2(0.2, 0.2);
        player->add_child(sprite1);

    ball = new CollisionObject();
    ball->name = "Ball";
    add_child(ball);

        ball_collision = new CollisionShape();
        ball_collision->name = "ball_collision";
        ball_collision->position = Vector2(100, 100);
        ball_collision->layer.push_back(WALL);
        ball_collision->mask.push_back(PLAYER);
        ball_collision->_size = Vector2(100, 100);
        ball->add_child(ball_collision);
        ball->set_collision_shape(ball_collision);

    test = new test_scene_2();
    test->name = "test";
    add_child(test);

    animate = new AnimationPlayer();
    animate->name = "Animation";
        AnimationPack bounce;
        bounce.length = 2.0;
        bounce.repeat = true;
            //
            AnimationTrack track1;
            track1.variable = &player->position.y;
            track1.add_node(0, 100);
            track1.add_node(0.5, 50);
            track1.add_node(1.5, 150);
            track1.add_node(2, 100);
            bounce.add_track(track1);
            //
            AnimationTrack track2;
            track2.variable = &player->scale.x;
            track2.add_node(0, 1);
            track2.add_node(0.5, 0.1);
            track2.add_node(1.5, 2);
            track2.add_node(2, 1);
            bounce.add_track(track2);
    animate->add_animation(bounce, "bounce");
    animate->set_animation("bounce");
    add_child(animate);
}

// ==============================================

void test_scene_2::_physics_process()
{
    if (Input.is_just_pressed(MOVE_UP)) emit_signal("run");
}

void test_scene_2::execute_signal(string signal_name)
{
    if (signal_name == "bom") boom();
}

// ==============================================

void test_scene_root::execute_signal(string signal_name)
{
    if (signal_name == "run") go();
    else if (signal_name == "on_just_collision") dance();
    else if (signal_name == "on_just_not_collision") stop();
}

void test_scene_root::_ready()
{
    test->connect_signal("run", this);
    connect_signal("bom", test);
    player->connect_signal("on_just_collision", this);
    player->connect_signal("on_just_not_collision", this);
}

void test_scene_root::_physics_process()
{
//    Vector2 direction;
//    direction.x = Input.get_action_length(MOVE_RIGHT) - Input.get_action_length(MOVE_LEFT);
//    direction.y = Input.get_action_length(MOVE_DOWN) - Input.get_action_length(MOVE_UP);
//    direction = direction.normalize();
//    direction *= 3;
//
//    player->move_and_slide(direction);

    if (Input.is_just_pressed(MOVE_UP))
    {
        animate->start();
        cout << "Start\n";
    }
    if (Input.is_just_pressed(MOVE_DOWN))
    {
        animate->stop();
        cout << "Stop\n";
    }
    if (Input.is_just_pressed(MOVE_LEFT))
    {
        animate->pause();
        cout << "Pause\n";
    }

    if (Input.is_just_pressed(BUTTON_CONSOLE)) show_tree();
}


void test_scene_root::go()
{
    cout << "\n";
}

void test_scene_root::dance()
{
    CollisionPack& collision = player->collision;
    cout << "Direct: " << collision.direct.x << " " << collision.direct.y << "\n";
    cout << "Distance: " << collision.distance.x << " " << collision.distance.y << "\n";
    cout << "Object: " << collision.object->name << "\n";
    if (player->collision.direct != Vector2().UP) cout << "NOT Collide UP\n";
}

void test_scene_root::stop()
{
    cout << "Stop\n";
}

