#include "core/application.hpp"
#include <iostream>

int main()
{
    try {
        Application app;
        return app.Run();
    } catch (const std::exception& exception) {
        std::cerr << "Fatal error: " << exception.what() << '\n';
        return 1;
    }
}
