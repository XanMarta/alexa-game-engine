#ifndef BONE1D_H_INCLUDED
#define BONE1D_H_INCLUDED

//
//  A polylines of connected point
//

#include "Vector2.h"
#include <vector>
using namespace std;

class Bone1D
{
    public:

        vector<Vector2> point;  // Vector2(position, data)


        void add_point(float _position, float data);

        float get_data_at(float _position);

};

#endif // BONE1D_H_INCLUDED
