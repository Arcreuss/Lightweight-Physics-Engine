cmake_minimum_required(VERSION 3.20)
project(lightweight_physics_engine LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)
find_package(OpenGL REQUIRED)

pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(GLM REQUIRED glm)

add_executable(engine
        src/main.cpp
        src/core/application.cpp
        src/physics/world.cpp
        src/render/debug_renderer.cpp
        src/glad.c
        src/math/vec2.cpp
)

target_include_directories(engine PRIVATE
        include
        ${GLFW_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
)

target_link_directories(engine PRIVATE
        ${GLFW_LIBRARY_DIRS}
)

target_link_libraries(engine PRIVATE
        ${GLFW_LIBRARIES}
        OpenGL::GL
)