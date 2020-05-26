#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <bits/stdc++.h>
#include <vector>
#include <map>
#include "Node_Base.h"
#include "Signal.h"
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


        void emit_signal(string signal_name);
        void connect_signal(string signal_name, void (*func)());


        void free();
        void free_child(string name = "");


        // Root method

        void ready();
        void process();
        void physics_process();

        Vector2 get_position();
        Vector2 get_scale();

    private:

        map<string, SignalPack> signal;

};


#endif // NODE_H_INCLUDED
