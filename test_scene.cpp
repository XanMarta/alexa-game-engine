#include "test_scene.h"





void test_scene::setup()
{
    root = new test_scene_root();
    root->name = "Root";

    Sprite* sprite = new Sprite();
    sprite->name = "sprite";
    sprite->image = BACKGROUND;
    sprite->scale = Vector2(0.5, 0.5);
    sprite->position += Vector2(30, 30);
    root->add_child(sprite);

    cout << "Setup completely\n";
    cout << root->get_child("sprite")->name << endl;

}

// ==============================================

void test_scene_root::_ready()
{
    cout << "test scene root ready\n";
}


void test_scene_root::_physics_process()
{
    if (Input.is_just_pressed(MOVE_DOWN)) cout << "Move down pressed\n";

    if (Input.is_just_released(MOVE_DOWN)) cout << "Move down released\n";

    if (Input.is_on_pressed(MOVE_DOWN)) cout << "Move down on pressed\n";

    if (Input.is_just_pressed(MOUSE_C)) cout << "Mouse pressed\n";

    if (Input.is_just_released(MOUSE_C)) cout << "Mouse released\n";

    if (Input.is_on_pressed(MOUSE_C)) cout << "Mouse on pressed\n";
}
