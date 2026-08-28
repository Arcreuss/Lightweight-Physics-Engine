//
// Created by arcreuss on 4/11/26.
//
#pragma once
#include <string>

struct vec2
{
    float x;
    float y;

    [[nodiscard]] std::string ToString() const;

#pragma region Operator Overload

    [[nodiscard]] vec2 operator+(vec2 const& other) const noexcept
    {
        return vec2{x + other.x, y + other.y};
    }

    [[nodiscard]] vec2 operator-(vec2 const& other) const noexcept
    {
        return vec2{x - other.x, y - other.y};
    }

    [[nodiscard]] vec2 operator*(float const scalar) const noexcept
    {
        return vec2 {x * scalar, y * scalar};
    }

    [[nodiscard]] vec2 operator/(float const scalar) const noexcept
    {
        return vec2 {x / scalar, y / scalar};
    }

    vec2& operator+=(vec2 const& other) noexcept
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    vec2& operator-=(vec2 const& other) noexcept
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    vec2& operator*=(float const scalar) noexcept
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    vec2& operator/=(float const scalar) noexcept
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

#pragma endregion
};