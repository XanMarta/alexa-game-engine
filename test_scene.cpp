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

    player = new CollisionObject();
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
        ball_collision->layer.push_back(WALL);
        ball_collision->mask.push_back(PLAYER);
        ball_collision->_size = Vector2(500, 20);
        ball->add_child(ball_collision);
        ball->set_collision_shape(ball_collision);

    test = new test_scene_2();
    test->name = "test";
    add_child(test);
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
    if (Input.is_on_pressed(MOVE_UP)) player->position.y -= 2;
    if (Input.is_on_pressed(MOVE_DOWN)) player->position.y += 2;
    if (Input.is_on_pressed(MOVE_LEFT)) player->position.x -= 2;
    if (Input.is_on_pressed(MOVE_RIGHT)) player->position.x += 2;
}


void test_scene_root::go()
{
    cout << "Go go\n";
}

void test_scene_root::dance()
{
    cout << "Dance till we die\n";
}

void test_scene_root::stop()
{
    cout << "Stop please\n";
}

