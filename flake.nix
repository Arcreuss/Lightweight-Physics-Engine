{
  description = "Lightweight C++ physics engine dev shell";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-25.11";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
      in {
        devShells.default = pkgs.mkShell {
          packages = with pkgs; [
            clang
            clang-tools
            cmake
            ninja
            gdb
            pkg-config
            glfw
            glm
            mesa
          ];

          shellHook = ''
            export CC=clang
            export CXX=clang++
            echo "C++ / OpenGL dev shell ready"
            echo "Compiler: $(clang++ --version | head -n 1)"
            echo "CMake: $(cmake --version | head -n 1)"
          '';
        };
      });
}
