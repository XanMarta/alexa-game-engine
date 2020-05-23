#include "hgame.h"

void play_game()
{
    Sprite man;
    if (init_console() && load_data())
    {
        cout << "init console\n";
        man.image = BACKGROUND;
        man.scale = Vector2(0.5, 0.5);
        man.position.x += 10;
        while (true)
        {
            check_event();
            if (is_exit_console()) break;

            if (Input.is_just_pressed(MOVE_DOWN))
            {
                cout << "Move down pressed\n";
            }
            if (Input.is_just_released(MOVE_DOWN))
            {
                cout << "Move down released\n";
            }
            if (Input.is_on_pressed(MOVE_DOWN))
            {
                cout << "Move down on pressed\n";
            }
            if (Input.is_just_pressed(MOUSE_C))
            {
                cout << "Mouse pressed\n";
            }
            if (Input.is_just_released(MOUSE_C))
            {
                cout << "Mouse released\n";
            }
            if (Input.is_on_pressed(MOUSE_C))
            {
                cout << "Mouse on pressed\n";
            }

            clear_console();
//            man.render();
            show_image();
        }
        cout << "Close console\n";
        close_console();
    }

}
