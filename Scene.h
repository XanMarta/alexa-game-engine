#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include "Node.h"
#include "hconsole.h"

const float DELTA = 1 / 60;
const float DELAY_TIME = DELTA * 1000;
const int PROCESS_FRAME_DIFF = 3;


class Scene
{
    public:

        Node* root = NULL;

        void run();

    protected:

        virtual void setup() {}

    private:

        void prepare_phase();
        void collision_phase();
        void process_phase();
        void render_phase();
        void wait_phase();
        void close_phase();

        bool is_running = true;
        int process_frame;
};


#endif // SCENE_H_INCLUDED
