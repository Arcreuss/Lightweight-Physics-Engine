#include "core/application.hpp"
#include <iostream>

#include "Body/Body.hpp"
#include "physics/world.hpp"

constexpr int MAX_STEP = 1000;

int main()
{
    PhysicsWorld physicsWorld;
    physicsWorld.Init();

    int step = 0;
    while (step != MAX_STEP)
    {
        if (step == MAX_STEP/2)
        {
            auto dynamicBody = std::make_unique<Body>();
            dynamicBody->SetPosition({10.f, 10.f});
            dynamicBody->SetAcceleration({1.2f, 1.4f});
            physicsWorld.AddToWorld(std::move(dynamicBody));
        }

        physicsWorld.Step(0.016f);
        std::cout << "iteration : " << step + 1 << std::endl;
        step++;
    }

    // OpenGL APP
    // try {
    //     Application app;
    //     return app.Run();
    // } catch (const std::exception& exception) {
    //     std::cerr << "Fatal error: " << exception.what() << '\n';
    //     return 1;
    // }

    return 0;
}
