#pragma once

#include <cmath>
#include <memory.h>
#include <limits>

namespace Math
{
    const float Pi = 3.1415926535f;
    const float TwoPi = Pi * 2.0f;
    inline bool NearZero(float val, float epsilon = 0.001f)
    {
        if (fabs(val) <= epsilon)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    inline float Abs(float value)
    {
            return fabs(value);
    }

    inline float Cos(float angle)
    {
        return cosf(angle);
    }

    inline float Sin(float angle)
    {
        return sinf(angle);
    }

    inline float Tan(float angle)
    {
        return tanf(angle);
    }

    inline float Atan2(float y, float x)
    {
        return atan2f(y, x);
    }

    inline float Cot(float angle)
    {
        return 1.0f / Tan(angle);
    }
}

class Vector1
{
public:
    float x;
    float y;

    Vector1()
        :x(0.0f)
        ,y(0.0f)
    {}

    explicit Vector1(float inX, float inY)
        :x(inX)
        ,y(inY)
    {}
    
    static const Vector1 Zero;
    static const Vector1 UnitX;
    static const Vector1 UnitY;
    static const Vector1 NegUnitX;
    static const Vector1 NegUnitY;
    
    // Vector addition (a + b)
    friend Vector1 operator+(const Vector1& a, const Vector1& b)
    {
        return Vector1(a.x + b.x, a.y + b.y);
    }

    // Vector subtraction (a - b)
    friend Vector1 operator-(const Vector1& a, const Vector1& b)
    {
        return Vector1(a.x - b.x, a.y - b.y);
    }
    
    friend Vector1 operator*(const Vector1& a, const Vector1& b)
    {
        return Vector1(a.x * b.x, a.y * b.y);
    }
    
    // Scalar multiplication
    friend Vector1 operator*(const Vector1& vec, float scalar)
    {
        return Vector1(vec.x * scalar, vec.y * scalar);
    }

    // Scalar multiplication
    friend Vector1 operator*(float scalar, const Vector1& vec)
    {
        return Vector1(vec.x * scalar, vec.y * scalar);
    }

    // Scalar *=
    Vector1& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }
    
    // Vector +=
    Vector1& operator+=(const Vector1& right)
    {
        x += right.x;
        y += right.y;
        return *this;
    }
    
    float LengthSq() const
    {
        return (x*x + y*y);
    }
};

