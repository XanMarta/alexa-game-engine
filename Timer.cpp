#include "Timer.h"


void Timer::start()
{
    is_running = true;
    start_time = get_time();
}

void Timer::stop()
{
    is_running = false;
}

void Timer::_physics_process()
{
    if (is_running)
    {
        float running_time = (get_time() - start_time) / 1000.0;
        if (running_time >= wait_time)
        {
            if (repeat)
            {
                start_time += wait_time * 1000.0;
            }
            else is_running = false;
            emit_signal("timeout");
        }
    }
}
