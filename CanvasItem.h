#ifndef CANVASITEM_H_INCLUDED
#define CANVASITEM_H_INCLUDED

#include "Node2D.h"
#include "hsdl.h"



class CanvasItem : public Node2D
{
    public:

        int layer = 1;          // max layer: 20. Small layer will be drawn first

        void show();
        void hide();

    protected:

        bool is_showing = true;
};

#endif // CANVASITEM_H_INCLUDED
