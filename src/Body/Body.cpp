//
// Created by arcreuss on 4/24/26.
//

#include <Body/Body.hpp>

void Body::Update(float deltaTime)
{
    m_Velocity += m_Acceleration * deltaTime;
    m_Position += m_Velocity * deltaTime;
}
