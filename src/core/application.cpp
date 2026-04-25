#include "core/application.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>

Application::Application()
{
    InitWindow();
}

Application::~Application()
{
    Shutdown();
}

int Application::Run()
{
    while (!glfwWindowShouldClose(m_window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    return 0;
}

void Application::InitWindow()
{
    if (glfwInit() == GLFW_FALSE)
    {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwSetErrorCallback(ErrorCallback);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(1280, 720, "Lightweight Physics Engine", nullptr, nullptr);
    if (m_window == nullptr)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cerr << "Failed to initialize GLAD\n";
        return;
    }

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << '\n';
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << '\n';

    glfwSetKeyCallback(m_window, KeyCallback);
    glfwSwapInterval(1);
}

void Application::Shutdown()
{
    if (m_window != nullptr)
    {
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    }

    glfwTerminate();
}

void Application::ErrorCallback(int error, const char *description)
{
    std::cout << "GLFW Error :" << description << std::endl;
}

void Application::KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
