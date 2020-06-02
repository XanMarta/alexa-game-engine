#ifndef CANVASITEM_H_INCLUDED
#define CANVASITEM_H_INCLUDED

#include "Node.h"


class CanvasItem : public Node
{
    public:

        int layer = 1;          // max layer: 20. Small layer will be drawn first

        float alpha = 255;

        void show();
        void hide();

    protected:

        bool is_showing = true;
};

#endif // CANVASITEM_H_INCLUDED
