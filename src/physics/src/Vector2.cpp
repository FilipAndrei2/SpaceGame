#include "Vector2.hpp"

#include <cmath>

using namespace Filip::Physics;

Vector2::Vector2(float x = 0, float y = 0)
    : x(x), y(y)
{ 

}

Vector2::Vector2(const Vector2& src)
    : x(src.x), y(src.y)
{

}

Vector2::~Vector2()
{

}



Vector2& Vector2::set(const float x, const float y)
{
    this->x = x;
    this->y = y;

    cache.invalidate();
    return *this;
}

Vector2& Vector2::normalize()
{
    float lenght = this->lenght();

    x /= lenght;
    y /= lenght;

    cache.invalidate();
    return *this;
}

Vector2& Vector2::add(const Vector2& other)
{
    this->x += other.x;
    this->y += other.y;

    cache.invalidate();
    return *this;
}

Vector2& Vector2::subtract(const Vector2& other)
{
    cache.invalidate();
    return this->add(-other);
}

Vector2& Vector2::scaleBy(float scalar)
{
    x *= scalar;
    y *= scalar;

    cache.invalidate();
    return *this;
}

Vector2& Vector2::rotateBy(const float radians)
{
    float sinAngle = std::sin(radians);
    float cosAngle = std::cos(radians);

    float oldX = x;
    
    x = x * cosAngle - y * sinAngle;
    y = oldX * sinAngle + y * cosAngle;

    cache.invalidate();
    return *this;
}

Vector2 Vector2::normalized() const
{
    return Vector2(x / this->lenght(), y / this->lenght());
}

Vector2 Vector2::rotatedBy(const float scalar) const
{
    return ;
}

float Vector2::lenght() const
{
    if (!cache.lenght.has_value())
    {
        cache.lenght.emplace(std::sqrt(x * x + y * y));
    }
    return cache.lenght.value();
}

float Vector2::sinTheta() const
{
    if (!cache.sinTheta.has_value())
    {
        cache.sinTheta.emplace(y / this->lenght());
    }
    return cache.sinTheta.value();
}

float Vector2::cosTheta() const
{
    if (!cache.cosTheta.has_value())
    {
        cache.cosTheta.emplace(x / this->lenght());
    }
    return cache.cosTheta.value();
}

bool Vector2::operator == (const Vector2& other)
{
    return ( (this->x == other.x) && (this->y == other.y) );
}

bool Vector2::operator != (const Vector2& other)
{
    return !( (this->x == other.x) && (this->y == other.y) );
}

Vector2 Vector2::operator + (const Vector2& other)
{
    return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator - (const Vector2& other)
{
    return Vector2(this->x - other.x, this->y - other.y);
}

Vector2 Vector2::operator * (const float scalar)
{
    return Vector2(this->x * scalar, this->y * scalar);
}

Vector2 Vector2::operator / (const float scalar)
{
    return Vector2(this->x / scalar, this->y / scalar);
}

