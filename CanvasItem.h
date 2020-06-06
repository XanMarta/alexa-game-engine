#ifndef CANVASITEM_H_INCLUDED
#define CANVASITEM_H_INCLUDED

#include "Node.h"
#include "hsdl.h"

struct color_modulation
{
    float r = 255.0;
    float g = 255.0;
    float b = 255.0;
    float a = 255.0;
};

class CanvasItem : public Node
{
    public:

        int layer = 1;          // max layer: 20. Small layer will be drawn first

        color_modulation modulation;

        void show();
        void hide();

    protected:

        bool is_showing = true;
};

#endif // CANVASITEM_H_INCLUDED
