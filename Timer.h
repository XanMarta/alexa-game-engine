#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

/*
    Signal:
        timeout
*/


#include "Node.h"
#include "hsdl.h"


class Timer : public Node
{
    public:

        float wait_time = 2.0;
        bool repeat = false;


        void start();
        void stop();

        void _physics_process();

    private:

        bool is_running = false;
        uint32_t start_time;
};

#endif // TIMER_H_INCLUDED
