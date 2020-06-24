#ifndef NODE2D_H_INCLUDED
#define NODE2D_H_INCLUDED

#include "Node.h"
#include "Color.h"

//
//  Work with 2D environment (position, rotation, modulation, alpha, ... )
//      with inheritance variables
//

class Node2D : public Node
{
    public:

        Node2D* parent_2d = NULL;
        vector<Node2D*> child_2d;

        // Element

        Vector2 position = Vector2().ZERO;
        Vector2 scale = Vector2().ONE;
        float rotation = 0.0;
        color_modulation modulation;

        Vector2 get_global_position();          // Write again
        Vector2 get_global_scale();
        color_modulation get_global_modulation();

        // Base Node method

        virtual void add_child(Node* new_child);
        virtual void add_child(Node2D* new_child);
        virtual void unlink_child(string name);
        virtual void clear_node();


};

#endif // NODE2D_H_INCLUDED
