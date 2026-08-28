#pragma once
#include <memory>
#include <vector>

#include "Body/Body.hpp"

class Body;

class PhysicsWorld
{
public:
    PhysicsWorld() = default;
    ~PhysicsWorld() = default;

    void Init();
    void AddToWorld(std::unique_ptr<Body> body);
    void Step(float deltaTime) const;
    void Clear();

private:
    std::vector<std::unique_ptr<Body>> m_Bodies = {};
};
