#include "core/application.hpp"
#include <iostream>

#include "Body/Body.hpp"
#include "physics/world.hpp"

int main()
{
    PhysicsWorld physicsWorld;
    physicsWorld.Init();

    int step = 0;
    while (step != 10000)
    {
        physicsWorld.Step(0.016f);
        step++;
    }
    physicsWorld.Clear();

    try {
        Application app;
        return app.Run();
    } catch (const std::exception& exception) {
        std::cerr << "Fatal error: " << exception.what() << '\n';
        return 1;
    }
}
