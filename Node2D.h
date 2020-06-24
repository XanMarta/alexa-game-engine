#ifndef NODE2D_H_INCLUDED
#define NODE2D_H_INCLUDED

#include "Node.h"


class Node2D : public Node
{
    public:

        Node2D* parent_2d = NULL;
        vector<Node2D*> child_2d;

        // Node method

        virtual void add_child(Node* new_child);
        virtual void add_child(Node2D* new_child);

        virtual void unlink_child(string name);

        void show(int num = 0)
        {
            for (int i = 0; i < num; i++)
            {
                cout << ".   ";
            }
            cout << name << "\n";
            for (int i = 0; i < child_2d.size(); i++)
            {
                child_2d[i]->show(num + 1);
            }
        }

    protected:

        virtual void clear_node();
};

#endif // NODE2D_H_INCLUDED
