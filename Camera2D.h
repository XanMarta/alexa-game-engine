#ifndef CAMERA2D_H_INCLUDED
#define CAMERA2D_H_INCLUDED

#include "Node.h"
#include "hconsole.h"


class Camera2D : public Node
{
    public:

        Vector2* anchor = NULL;
        Vector2 margin = Vector2().ZERO;
        Vector2 limit_horizontal = Vector2(-500, 1000);
        Vector2 limit_vertical = Vector2(-500, 1000);

        Vector2 zoom = Vector2().ONE;
        Vector2 global_position = Vector2().ZERO;   // Should not change this


        void set_camera(Vector2* anchor, Vector2 margin);
        void set_default_camera();


        void _physics_process();
        void _exit_tree();

    private:

        bool is_default = false;

};


#endif // CAMERA2D_H_INCLUDED
