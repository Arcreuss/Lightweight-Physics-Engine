//
// Created by arcreuss on 4/11/26.
//
#pragma once
#include <sstream>

#ifndef LIGHTWEIGHT_PHYSICS_ENGINE_VEC2_HPP
#define LIGHTWEIGHT_PHYSICS_ENGINE_VEC2_HPP

struct vec2
{
    float x;
    float y;

    [[nodiscard]] std::string ToString() const;

#pragma region Operator Overload

    vec2 operator+(vec2 const& other) const
    {
        return vec2{x + other.x, y + other.y};
    }

    vec2 operator-(vec2 const& other) const
    {
        return vec2{x - other.x, y - other.y};
    }

    vec2 operator*(float scalar) const
    {
        return vec2 {x * scalar, y * scalar};
    }

    vec2 operator/(float scalar) const
    {
        return vec2 {x / scalar, y / scalar};
    }

    vec2& operator+=(vec2 const& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    vec2& operator-=(vec2 const& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    vec2& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    vec2& operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

#pragma endregion
};

#endif //LIGHTWEIGHT_PHYSICS_ENGINE_VEC2_HPP
