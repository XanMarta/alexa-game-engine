#include "Node2D.h"


Vector2 Node2D::get_global_position()
{
    if (parent_2d != NULL) return parent_2d->get_global_position() + this->position;
    else return this->position;
}

Vector2 Node2D::get_global_scale()
{
    if (parent_2d != NULL) return parent_2d->get_global_scale() * this->scale;
    else return this->scale;
}

color_modulation Node2D::get_global_modulation()
{
    if (parent_2d != NULL)
    {
        color_modulation p_mod = parent_2d->get_global_modulation();
        return color_modulation(modulation.r + p_mod.r, modulation.g + p_mod.g, modulation.b + p_mod.b, modulation.a + p_mod.a);
    }
    else return this->modulation;
}



void Node2D::add_child(Node* new_child)
{
    Node::add_child(new_child);
}

void Node2D::add_child(Node2D* new_child)
{
    child_2d.push_back(new_child);
    new_child->parent_2d = this;
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
