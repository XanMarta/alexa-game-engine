#include "Bone1D.h"


void Bone1D::add_point(float _position, float data)
{
    point.push_back(Vector2(_position, data));
}


float Bone1D::get_data_at(float _position)
{
    int point_set = 0;
    while (_position > point[point_set].x)
    {
        point_set++;
        if (point_set == point.size()) return point[point_set - 1].y;
    }
    Vector2 _ratio = point[point_set] - point[point_set - 1];
    if (_ratio.x == 0) _ratio.x = 1;
    return point[point_set - 1].y + (_position - point[point_set - 1].x) * _ratio.y / _ratio.x;
}
