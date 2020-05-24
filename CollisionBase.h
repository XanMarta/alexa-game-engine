#ifndef COLLISIONBASE_H_INCLUDED
#define COLLISIONBASE_H_INCLUDED




enum Collision_Layer
{
    WALL, PLAYER,

    NONE_COLLISION,
    TOTAL_COLLISION
};


// Call in main scene
void check_collision();



#endif // COLLISIONBASE_H_INCLUDED
