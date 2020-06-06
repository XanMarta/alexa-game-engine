#ifndef VECTOR2_H_INCLUDED
#define VECTOR2_H_INCLUDED

/*
    UP:     Vector2(0, -1)
    DOWN:   Vector2(0, 1)
*/

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
    Vector2 operator*(const Vector2& _vector2);
    Vector2 operator/(const Vector2& _vector2);

    void operator+=(const Vector2& _vector2);
    void operator-=(const Vector2& _vector2);
    void operator*=(const float& _number);
    void operator/=(const float& _number);

    bool operator==(const Vector2& _vector2);
    bool operator!=(const Vector2& _vector2);


    Vector2 power(const float& amount);

    Vector2 bounce(const float& amount = 1.0);
    float dot(const Vector2& _vector2);
    float length();
    float distance_to(const Vector2& _vector2);
    Vector2 direction_to(Vector2& _vector2);
    Vector2 normalize();

};


#endif // VECTOR2_H_INCLUDED
