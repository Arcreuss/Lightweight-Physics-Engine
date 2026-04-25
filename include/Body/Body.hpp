//
// Created by arcreuss on 4/24/26.
//
#pragma once
#include "math/vec2.hpp"

#ifndef LIGHTWEIGHT_PHYSICS_ENGINE_BODY_HPP
#define LIGHTWEIGHT_PHYSICS_ENGINE_BODY_HPP

class Body
{
public:
    Body()
    {
        m_Position = {0.f, 0.f};
        m_Velocity = {0.f, 0.f};
        m_Acceleration = {0.f, 0.f};
    }

    Body(vec2 position)
    {
        m_Position = {m_Position.x = position.x, m_Position.y = position.y};
        m_Velocity = {0.f, 0.f};
        m_Acceleration = {0.f, 0.f};
    }

    void SetPosition(vec2 const value) { m_Position = value; }
    [[nodiscard]] vec2 GetPosition() const { return m_Position; }
    void SetVelocity(vec2 const value) { m_Velocity = value; }
    [[nodiscard]] vec2 GetVelocity() const { return m_Velocity; }
    void SetAcceleration(vec2 const value) { m_Acceleration = value; }
    [[nodiscard]] vec2 GetAcceleration() const { return m_Acceleration; }

    void Update(float deltaTime);

private:
    vec2 m_Position{};
    vec2 m_Velocity{};
    vec2 m_Acceleration{};
};


#endif //LIGHTWEIGHT_PHYSICS_ENGINE_BODY_HPP