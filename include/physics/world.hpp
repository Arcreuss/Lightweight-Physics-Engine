#pragma once
#include <vector>

#include "Body/Body.hpp"

class Body;

class PhysicsWorld
{
public:
    void Init();
    void AddToWorld(Body* body);
    void Step(float deltaTime);
    void Clear();

private:
    std::vector<Body*> m_Bodies = {};
};
