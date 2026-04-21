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
    static void ErrorCallback(int error, const char* description);
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    GLFWwindow* m_window = nullptr;
};
