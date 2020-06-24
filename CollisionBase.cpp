#include "CollisionBase.h"
#include "CollisionObject.h"


struct _Collision_Layer
{
    vector<CollisionShape*> object;
};

_Collision_Layer layer[TOTAL_COLLISION];

bool on_collision(CollisionShape* shape1, CollisionShape* shape2);

// ====================================================

void update_collision(CollisionShape* shape)
{
    for (unsigned int i = 0; i < shape->layer.size(); i++)
    {
        layer[shape->layer[i]].object.push_back(shape);
    }
}

// ====================================================

void check_collision()
{
    for (int i = 0; i < NONE_COLLISION; i++)
    {
        for (int j = 0; j < layer[i].object.size(); j++)
        {
            CollisionShape* object_check = layer[i].object[j];
            if (object_check->object->monitoring == false) continue;

            for (int k = 0; k < object_check->mask.size(); k++)
            {
                Collision_Layer layer_check = object_check->mask[k];
                for (int l = 0; l < layer[layer_check].object.size(); l++)
                {
                    CollisionShape* object_checking = layer[layer_check].object[l];
                    if (object_checking->object->monitorable == false) continue;

                    if (on_collision(object_check, object_checking))
                    {
                        object_check->object->check_collide(true);
                    }
                    else object_check->object->check_collide(false);
                }
            }
        }
    }

    // Clear
    for (int i = 0; i < NONE_COLLISION; i++)
    {
        layer[i].object.clear();
    }
}

// ====================================================

bool on_collision(CollisionShape* shape1, CollisionShape* shape2)
{
    CollisionPack& collision = shape1->object->collision;
    collision.reset();

    Vector2 pos1 = shape1->get_global_position();
    Vector2 pos2 = shape2->get_global_position();

    if (pos1.x + shape1->_size.x < pos2.x) return false;
    if (pos2.x + shape2->_size.x < pos1.x) return false;
    if (pos1.y + shape1->_size.y < pos2.y) return false;
    if (pos2.y + shape2->_size.y < pos1.y) return false;


    collision.object = shape2->object;
    collision.is_collision = true;

    if (pos1.x < pos2.x)
    {
        collision.direct.x++;
        collision.distance.x = pos1.x + shape1->_size.x - pos2.x;
    }
    else
    {
        collision.direct.x--;
        collision.distance.x = pos2.x + shape2->_size.x - pos1.x;
    }
    if (pos1.y < pos2.y)
    {
        collision.direct.y++;
        collision.distance.y = pos1.y + shape1->_size.y - pos2.y;
    }
    else
    {
        collision.direct.y--;
        collision.distance.y = pos2.y + shape2->_size.y - pos1.y;
    }

    if (collision.distance.x < collision.distance.y)
    {
        collision.direct.y = 0;
    }
    else
    {
        collision.direct.x = 0;
    }

    return true;
}
