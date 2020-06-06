#include "Vector2.h"
#include <cmath>


Vector2 Vector2::ZERO   = Vector2(0.0, 0.0);
Vector2 Vector2::ONE    = Vector2(1.0, 1.0);
Vector2 Vector2::UP     = Vector2(0.0, -1.0);
Vector2 Vector2::LEFT   = Vector2(-1.0, 0.0);
Vector2 Vector2::DOWN   = Vector2(0.0, 1.0);
Vector2 Vector2::RIGHT  = Vector2(1.0, 0.0);


Vector2::Vector2()
{
    x = 0.0;
    y = 0.0;
}

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2 Vector2::operator+(const Vector2& _vector2)
{
    return Vector2(this->x + _vector2.x, this->y + _vector2.y);
}

Vector2 Vector2::operator-(const Vector2& _vector2)
{
    return Vector2(this->x - _vector2.x, this->y - _vector2.y);
}

Vector2 Vector2::operator*(const float& _number)
{
    return Vector2(this->x * _number, this->y * _number);
}

Vector2 Vector2::operator/(const float& _number)
{
    return Vector2(this->x / _number, this->y / _number);
}

Vector2 Vector2::operator*(const Vector2& _vector2)
{
    return Vector2(this->x * _vector2.x, this->y * _vector2.y);
}

Vector2 Vector2::operator/(const Vector2& _vector2)
{
    return Vector2(this->x / _vector2.x, this->y / _vector2.y);
}




void Vector2::operator+=(const Vector2& _vector2)
{
    *this = *this + _vector2;
}

void Vector2::operator-=(const Vector2& _vector2)
{
    *this = *this - _vector2;
}

void Vector2::operator*=(const float& _number)
{
    *this = *this * _number;
}

void Vector2::operator/=(const float& _number)
{
    *this = *this / _number;
}


bool Vector2::operator==(const Vector2& _vector2)
{
    return (this->x == _vector2.x && this->y == _vector2.y);
}

bool Vector2::operator!=(const Vector2& _vector2)
{
    return (this->x != _vector2.x || this->y != _vector2.y);
}


Vector2 Vector2::power(const float& amount)
{
    return Vector2(pow(this->x, amount), pow(this->y, amount));
}

Vector2 Vector2::bounce(const float& amount)
{
    return ((*this * -1.0) * amount);
}

float Vector2::dot(const Vector2& _vector2)
{
    return this->x * _vector2.x + this->y * _vector2.y;
}

float Vector2::length()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

float Vector2::distance_to(const Vector2& _vector2)
{
    return (*this - _vector2).length();
}

Vector2 Vector2::direction_to(Vector2& _vector2)
{
    return (_vector2 - *this);
}

Vector2 Vector2::normalize()
{
    if (this->length() == 0) return ZERO;
    return (*this / this->length());
}
