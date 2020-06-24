#include "VisibilityNotifier.h"
#include "Rect2D.h"
#include "RenderPack.h"

bool is_showing = true;

bool VisibilityNotifier::is_on_screen()
{
    return on_screen;
}


void VisibilityNotifier::_physics_process()
{
    Rect2D rect_check = Rect2D(get_global_position(), _size);
    Rect2D camera_check = Rect2D(*Camera.position, Camera._size * (*Camera.zoom).power(-1));
    bool checking = rect_check.is_on_sight(camera_check);

    if (checking)
    {
        if (!on_screen) emit_signal("screen_enter");
    }
    else
    {
        if (on_screen) emit_signal("screen_exit");
    }
    on_screen = checking;

    if (is_showing)
    {
        update_render_collision(rect_check.position, _size, {0xFF, 0x00, 0x00});
    }
}
