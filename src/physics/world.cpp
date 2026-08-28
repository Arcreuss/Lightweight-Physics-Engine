#include "physics/world.hpp"

#include <Body/Body.hpp>
#include <iostream>

void PhysicsWorld::Init()
{
    std::unique_ptr<Body> body1 = std::make_unique<Body>();
    body1->SetPosition({5.f, 3.f});
    body1->SetAcceleration({1.f, 1.2f});
    std::cout << "Body1 Init " << body1->GetPosition().ToString() << std::endl;
    AddToWorld(std::move(body1));


    std::unique_ptr<Body> body2 = std::make_unique<Body>();
    body2->SetPosition({-1.f, -2.f});
    body2->SetAcceleration({-2.f, 0.f});
    std::cout << "Body2 Init " << body2->GetPosition().ToString() << std::endl;
    AddToWorld(std::move(body2));
}

void PhysicsWorld::AddToWorld(std::unique_ptr<Body> body)
{
    m_Bodies.push_back(std::move(body));
}

void PhysicsWorld::Step(float const deltaTime) const
{
    size_t const size = m_Bodies.size();
    for (size_t i = 0; i < size; ++i)
    {
        std::unique_ptr<Body> const & body = m_Bodies[i];
        [[unlikely]] if (body == nullptr)
        {
            continue;
        }

        body->Update(deltaTime);
        std::cout << "Body[" << i << "] Update /Position " << body->GetPosition().ToString() << " /Velocity " << body->GetVelocity().ToString() << " /Acceleration " << body->GetAcceleration().ToString() << std::endl;
    }
}

void PhysicsWorld::Clear()
{
    m_Bodies.clear();
}
