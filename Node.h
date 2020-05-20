#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <bits/stdc++.h>
#include <vector>
#include "Node_Base.h"
using namespace std;


class Node : public Node_Base
{
    public:

        // Variables

        string name = "";

        Node* parent = NULL;
        vector<Node*> child;


        // Method

        Node();
        Node(string name);
        ~Node();

        void add_child(Node* new_child);
        Node* get_child(string name);
        void unlink_child(string name);

        void free();
        void free_child(string name = "");


        // Root method

        void ready();
        void process();
        void physics_process();

        Vector2 get_position();
        Vector2 get_scale();

};


#endif // NODE_H_INCLUDED
