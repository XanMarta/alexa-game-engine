#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include "Node.h"
#include "hconsole.h"
#include "RenderPack.h"



const float DELTA = 1 / 60;
const float DELAY_TIME = DELTA * 1000;
const int PROCESS_FRAME_DIFF = 2;


class Scene
{
    public:

        virtual ~Scene() {}

        Node* root = NULL;

        void run();
        void close();

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

        int temp = 0;
};


#endif // SCENE_H_INCLUDED
