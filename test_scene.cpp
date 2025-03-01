#include "test_scene.h"


void test_scene::setup()
{
    test_scene_root* _root = new test_scene_root();
    _root->setup();
    set_root(_root);
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

    character = new Node2D();
    character->name = "Character";
    add_child(character);

        player = new KinematicBody();
        player->name = "Player";
        player->position = Vector2(20, 100);
        character->add_child(player);

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

            visible_check = new VisibilityNotifier();
            visible_check->name = "visible_check";
            visible_check->_size = Vector2(65, 65);
            player->add_child(visible_check);

    ball = new CollisionObject();
    ball->name = "Ball";
    ball->position = Vector2(100, 100);
    ball->is_static_body = true;
    add_child(ball);

        ball_collision = new CollisionShape();
        ball_collision->name = "ball_collision";
        ball_collision->layer.push_back(WALL);
        ball_collision->mask.push_back(PLAYER);
        ball_collision->_size = Vector2(100, 100);
        ball->add_child(ball_collision);
        ball->set_collision_shape(ball_collision);

        wal = new Sprite();
        wal->name = "image wall";
        wal->image = BACKGROUND;
        wal->scale = Vector2(0.1, 0.1);
        ball->add_child(wal);

        ball_check = new VisibilityNotifier();
        ball_check->name = "visibility ball";
        ball_check->_size = Vector2(100, 100);
        ball->add_child(ball_check);

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

        AnimationPack fade;
        fade.length = 5.0;
        fade.repeat = true;
            //
            AnimationTrack track3;
            track3.variable = &sprite1->modulation.a;
            track3.add_node(0, 255.0);
            track3.add_node(5.0, 0);
            fade.add_track(track3);

    animate->add_animation(fade, "fade");
    animate->add_animation(bounce, "bounce");
    animate->set_animation("bounce");
    add_child(animate);

    timer = new Timer();
    timer->name = "timer";
    timer->wait_time = 1.5;
    timer->repeat = true;
    add_child(timer);

    node1 = new Node2D();
    node1->name = "Node1";
    add_child(node1);

        cam = new Camera2D();
        cam->name = "Camera";
        cam->set_camera(&player->position);
//        cam->set_default_camera();
        node1->add_child(cam);
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

void test_scene_root::execute_signal(string func_name)
{
         if (func_name == "player_enter") player_enter();
    else if (func_name == "player_exit") player_exit();
    else if (func_name == "ball_out_screen") ball_out();
}

void test_scene_root::_ready()
{
    visible_check->connect_signal("screen_enter", this, "player_enter");
    visible_check->connect_signal("screen_exit", this, "player_exit");
    ball_check->connect_signal("screen_exit", this, "ball_out_screen");
    ball_check->connect_signal("screen_exit", this, "player_exit");

}

void test_scene_root::_physics_process()
{
    Vector2 direction;
    direction.x = Input.get_action_length(MOVE_RIGHT) - Input.get_action_length(MOVE_LEFT);
    direction.y = Input.get_action_length(MOVE_DOWN) - Input.get_action_length(MOVE_UP);
    direction = direction.normalize();


    velocity.x = direction.x * 3;
    if (direction.y < 0) velocity.y = -5;
    velocity.y += 0.3;

    velocity = player->move_and_slide(velocity);

    ball->position += ball_velocity;

//    if (player->collision.is_collision)
//    {
//        cout << "Collision. Direct: " << player->collision.direct.x << " " << player->collision.direct.y << "\n";
//    }
//    cout << "Velocity: " << velocity.x << " " << velocity.y << "\n";

    if (Input.is_just_pressed(BUTTON_CONSOLE))
    {
        cam->zoom += Vector2(0.1, 0.1);
    }
    if (Input.is_just_pressed(MOUSE_C))
    {
        character->modulation.r += 10;
    }
}

void test_scene_root::_enter_tree()
{
    cout << "Test scene root enter tree\n";
}

void test_scene_root::_exit_tree()
{
    cout << "Test scene root exit tree\n";
}



void test_scene_root::player_enter()
{
    cout << "Player enter screen\n";
}

void test_scene_root::player_exit()
{
    cout << "Player exit screen\n";
}

void test_scene_root::ball_out()
{
    cout << "Ball out\n";
    ball_velocity.x *= -1.0;
}

