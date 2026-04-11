# lightweight-physics-engine

Small starter project for a lightweight C++ physics engine with GLFW + OpenGL + GLM on NixOS.

## Run

```bash
nix develop
cmake -S . -B build -G Ninja
cmake --build build
./build/engine
```
