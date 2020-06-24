#include "Node2D.h"

void Node2D::add_child(Node* new_child)
{
    Node::add_child(new_child);
}

void Node2D::add_child(Node2D* new_child)
{
    child_2d.push_back(new_child);
    Node::add_child(new_child);
}

void Node2D::unlink_child(string name)
{
    for (int i = 0; i < child_2d.size(); i++)
    {
        if (child_2d[i]->name == name)
        {
            child_2d[i]->parent_2d = NULL;
            child_2d.erase(child_2d.begin() + i);
            break;
        }
    }
    Node::unlink_child(name);
}

void Node2D::clear_node()
{
    if (parent_2d != NULL)
    {
        for (int i = 0; i < parent_2d->child_2d.size(); i++)
        {
            if (parent_2d->child_2d[i]->name == this->name)
            {
                parent_2d->child_2d.erase(parent_2d->child_2d.begin() + i);
                break;
            }
        }
    }
    delete this;
}
