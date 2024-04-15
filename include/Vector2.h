#pragma once

#include <cmath>

class Vector2
{
public:
    float x, y;

public:
    Vector2() = default;
    ~Vector2() = default;

    Vector2(float x, float y) : x(x), y(y) {}

    float magnitude() const
    {
        return sqrt(x * x + y * y);
    }

    void normalize()
    {
        float mag = magnitude();
        if (mag > 0.0f)
        {
            x /= mag;
            y /= mag;
        }
    }

    float dot(const Vector2 &other) const
    {
        return x * other.x + y * other.y;
    }

    Vector2 operator+(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(const Vector2 &other) const
    {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 operator*(float scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }

    Vector2 operator/(float scalar) const
    {
        return Vector2(x / scalar, y / scalar);
    }

    Vector2 &operator+=(const Vector2 &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2 &operator-=(const Vector2 &other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2 &operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2 &operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }
};