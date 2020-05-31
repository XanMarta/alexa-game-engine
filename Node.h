#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <bits/stdc++.h>
#include <vector>
#include <map>
#include "Node_Base.h"
using namespace std;


class SignalPack;

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
        void connect_signal(string signal_name, Node* target);
        virtual void execute_signal(string signal_name) {}


        void free();
        void free_child(string name = "");


        // Root method

        void ready();
        void process();
        void physics_process();

        Vector2 get_position();
        Vector2 get_scale();

        // Debug method

        void show_tree(int number = 1);

    private:

        map<string, SignalPack> signal;

};

// =========================================================

class SignalPack
{
    public:

        void emit(string signal_name);
        void connect(Node* node);

    private:

        vector<Node*> target;
};

// =========================================================

#endif // NODE_H_INCLUDED
