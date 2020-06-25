#include "Node.h"
#include "hbase.h"

Node::Node()
{
    name = "Node" + to_string(random(1000, 90000));
}

Node::Node(string name)
{
    this->name = name;
}

Node::~Node()
{
//     cout << "Destructor of " << name << "\n";
}

void Node::add_child(Node* new_child)
{
    child.push_back(new_child);
    new_child->parent = this;
    new_child->enter_tree();
}

Node* Node::get_child(string name)
{
    for (int i = 0; i < child.size(); i++)
    {
        if (child[i]->name == name) return child[i];
    }
    cout << "No child has name " << name << endl;
    return NULL;
}

void Node::unlink_child(string name)
{
    for (int i = 0; i < child.size(); i++)
    {
        if (child[i]->name == name)
        {
            child[i]->parent = NULL;
            child.erase(child.begin() + i);
            break;
        }
    }
}

void Node::emit_signal(string signal_name)
{
    if (signal.count(signal_name) > 0) signal[signal_name].emit(signal_name);
}

void Node::connect_signal(string signal_name, Node* target, string func_name)
{
    signal[signal_name].connect(target, func_name);
}

void Node::free()
{
    free_child();
    if (parent != NULL)
    {
        parent->free_child(this->name);
    }
    else
    {
        exit_tree();
        clear_node();
    }
}

void Node::free_child(string name)
{
    if (name == "")
    {
        for (int i = 0; i < child.size(); i++)
        {
            child[i]->free_child();
            child[i]->exit_tree();
            child[i]->clear_node();
            child[i] = NULL;
        }
        child.clear();
    }
    else
    {
        for (int i = 0; i < child.size(); i++)
        {
            if (child[i]->name == name)
            {
                child[i]->free_child();
                child[i]->exit_tree();
                child[i]->clear_node();
                child[i] = NULL;
                child.erase(child.begin() + i);
                break;
            }
        }
    }
}

void Node::clear_node()
{
    delete this;
}


// ===================================================


void Node::ready()
{
    _ready();
    for (int i = 0; i < child.size(); i++)
    {
        child[i]->ready();
    }
}

void Node::process()
{
    _process();
    for (int i = 0; i < child.size(); i++)
    {
        child[i]->process();
    }
}

void Node::physics_process()
{
    _physics_process();
    for (int i = 0; i < child.size(); i++)
    {
        child[i]->physics_process();
    }
}

void Node::enter_tree()
{
    _enter_tree();
}

void Node::exit_tree()
{
    _exit_tree();
}


void Node::show_tree(int number)
{
    cout << number;
    for (int i = 1; i <= number; i++) cout << "   .";
    cout << name << "\n";
    for (int i = 0; i < child.size(); i++)
    {
        child[i]->show_tree(number + 1);
    }
}


// ===========================================================

SignalTarget::SignalTarget(Node* node, string func_name)
{
    this->node = node;
    this->func_name = func_name;
}

void SignalPack::emit(string signal_name)
{
    for (int i = 0; i < target.size(); i++)
    {
        target[i].node->execute_signal(target[i].func_name);
    }
}

void SignalPack::connect(Node* node, string func_name)
{
    target.push_back(SignalTarget(node, func_name));
}
