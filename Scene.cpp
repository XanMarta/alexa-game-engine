#include "Scene.h"
#include "CollisionBase.h"


void Scene::run()
{
    setup();
    if (root != NULL)
    {
        prepare_phase();
        while (is_running)
        {
            clear_console();
            check_event();
            collision_phase();
            process_phase();
            render_phase();
            if (is_exit_console()) is_running = false;
            wait_phase();
        }
        close_phase();
    }
}

void Scene::close()
{
    is_running = false;
}

void Scene::prepare_phase()
{
    root->ready();
    process_frame = 1;
    is_running = true;
}

void Scene::collision_phase()
{
    check_collision();
}

void Scene::process_phase()
{
    root->physics_process();
    if (process_frame == PROCESS_FRAME_DIFF)
    {
        root->process();
        process_frame = 1;
    }
    else process_frame++;
}

void Scene::render_phase()
{
    show_render();
    show_image();
}

void Scene::wait_phase()
{

}

void Scene::close_phase()
{
    root->free();
}


