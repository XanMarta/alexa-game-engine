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
    player = new Node("player");
    add_child(player);

    sprite1 = new Sprite();
    sprite1->name = "sprite1";
    sprite1->image = BACKGROUND;
    sprite1->scale = Vector2(0.2, 0.2);
    player->add_child(sprite1);

    sprite2 = new Sprite();
    sprite2->name = "sprite2";
    sprite2->image = BACKGROUND;
    sprite2->fix_to_size(Vector2(360, 360));
    sprite2->position = Vector2(360, 200);
    player->add_child(sprite2);
}


// ==============================================


void test_scene_root::_physics_process()
{
    if (Input.is_on_pressed(MOVE_UP)) player->position.y -= 1;
    if (Input.is_on_pressed(MOVE_DOWN)) player->position.y += 1;
    if (Input.is_on_pressed(MOVE_LEFT)) player->position.x -= 1;
    if (Input.is_on_pressed(MOVE_RIGHT)) player->position.x += 1;
}
