#include "Node.h"


Node::Node()
{
    name = "Node";
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

void Node::connect_signal(string signal_name, Node* target)
{
    signal[signal_name].connect(target);
}

void Node::free()
{
    free_child();
    if (parent != NULL)
    {
        parent->free_child(this->name);
    }
    else delete this;
}

void Node::free_child(string name)
{
    if (name == "")
    {
        for (int i = 0; i < child.size(); i++)
        {
            child[i]->free_child();
            delete child[i];
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
                delete child[i];
                child[i] = NULL;
                child.erase(child.begin() + i);
                break;
            }
        }
    }

}


// ===================================================


void Node::ready()
{
    for (int i = 0; i < child.size(); i++)
    {
        child[i]->ready();
    }
    _ready();
}

void Node::process()
{
    for (int i = 0; i < child.size(); i++)
    {
        child[i]->process();
    }
    _process();
}

void Node::physics_process()
{
    for (int i = 0; i < child.size(); i++)
    {
        child[i]->physics_process();
    }
    _physics_process();
}

Vector2 Node::get_position()
{
    if (parent != NULL) return parent->get_position() + this->position;
    else return this->position;
}

Vector2 Node::get_scale()
{
    if (parent != NULL) return parent->get_scale() * this->scale;
    else return this->scale;
}


// ===========================================================

void SignalPack::emit(string signal_name)
{
    for (int i = 0; i < target.size(); i++)
    {
        target[i]->execute_signal(signal_name);
    }
}

void SignalPack::connect(Node* node)
{
    target.push_back(node);
}
