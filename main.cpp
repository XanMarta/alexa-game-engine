#include "hconsole.h"
#include "ddata.h"

#include "test_scene.h"


int main(int argc, char* argv[])
{
    if (init_console() && load_data())
    {

        Scene* root = new test_scene();
        root->run();
        delete root;

        close_console();
    }



    return 0;

}
