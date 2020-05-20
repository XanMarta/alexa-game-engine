#include "test_scene.h"





void test_scene::setup()
{
    Sprite* sprite = new test_scene_root();
    sprite->image = BACKGROUND;
    sprite->scale = Vector2(0.5, 0.5);
    sprite->position += Vector2(30, 30);

    root = sprite;

}

// ==============================================

void test_scene_root::_ready()
{
    cout << "test scene root ready\n";
}

void test_scene_root::_process()
{


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
