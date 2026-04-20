#pragma once

struct GLFWwindow;

class Application
{
public:
    Application();
    ~Application();

    int Run();

private:
    void InitWindow();
    void Shutdown();

    GLFWwindow* m_window = nullptr;
};
