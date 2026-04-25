#include "physics/world.hpp"

#include <iostream>

#include "Body/Body.hpp"

void PhysicsWorld::Init()
{
    Body* body1 = new Body;
    body1->SetPosition({5.f, 3.f});
    body1->SetAcceleration(vec2{1.f, 0.f});
    std::cout << "Body1 Init " << body1->GetPosition().ToString() << std::endl;
    AddToWorld(body1);


    Body* body2 = new Body;
    body2->SetPosition({-1.f, -2.f});
    body2->SetAcceleration(vec2{-2.f, 0.f});
    std::cout << "Body2 Init " << body2->GetPosition().ToString() << std::endl;
    AddToWorld(body2);
}

void PhysicsWorld::AddToWorld(Body* body)
{
    m_Bodies.push_back(body);
}

void PhysicsWorld::Step(float deltaTime)
{
    (void)deltaTime;

    for (size_t i = 0; i < m_Bodies.size(); ++i)
    {
        Body* const body = m_Bodies[i];
        if (body == nullptr)
        {
            continue;
        }

        body->Update(deltaTime);
        std::cout << "Body" << i << " Update /Position " << body->GetPosition().ToString() << " /Velocity " << body->GetVelocity().ToString() << " /Acceleration " << body->GetAcceleration().ToString() << std::endl;
    }
}

void PhysicsWorld::Clear()
{
    for (Body* const body : m_Bodies)
    {
        if (body == nullptr)
        {
            continue;
        }

        free(body);
    }
}
