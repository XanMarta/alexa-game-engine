#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <bits/stdc++.h>
#include <vector>
#include <map>
#include "Node_Base.h"
using namespace std;

struct SignalPair;
class SignalPack;

class Node : public Node_Base
{
    public:

        // Variables

        string name = "Node";           // Must be set in game. Each node has different name

        Node* parent = NULL;
        vector<Node*> child;


        // Method

        Node();
        Node(string name);
        ~Node();

            // Signal

        void emit_signal(string signal_name);
        void connect_signal(string signal_name, Node* target, string func_name);
        virtual void execute_signal(string func_name) {}

            // Child method

        Node* get_child(string name);

        virtual void add_child(Node* new_child);
        virtual void unlink_child(string name);

        virtual void free();
        virtual void free_child(string name = "");


            // Root method

        void ready();
        void process();
        void physics_process();
        void enter_tree();
        void exit_tree();

            // Debug method

        void show_tree(int number = 1);


    private:

        map<string, SignalPack> signal;

    protected:

        virtual void clear_node();

};

// =========================================================

struct SignalTarget
{
    Node* node;
    string func_name;

    SignalTarget(Node* node, string func_name);
};

class SignalPack
{
    public:

        void emit(string signal_name);
        void connect(Node* node, string func_name);

    private:

        vector<SignalTarget> target;
};

// =========================================================

#endif // NODE_H_INCLUDED
