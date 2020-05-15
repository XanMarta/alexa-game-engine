#ifndef VECTOR2_H_INCLUDED
#define VECTOR2_H_INCLUDED



struct Vector2
{
    float x, y;


    static Vector2 ZERO;
    static Vector2 ONE;
    static Vector2 UP;
    static Vector2 LEFT;
    static Vector2 DOWN;
    static Vector2 RIGHT;



    Vector2();
    Vector2(float x, float y);
    ~Vector2() {}



    Vector2 operator+(const Vector2& _vector2);
    Vector2 operator-(const Vector2& _vector2);
    Vector2 operator*(const float& _number);
    Vector2 operator/(const float& _number);

    void operator+=(const Vector2& _vector2);
    void operator-=(const Vector2& _vector2);
    void operator*=(const float& _number);
    void operator/=(const float& _number);



    float dot(const Vector2& _vector2);
    float length();
    float distance_to(const Vector2& _vector2);
    Vector2 direction_to(Vector2& _vector2);
    Vector2 normalize();

};


#endif // VECTOR2_H_INCLUDED
