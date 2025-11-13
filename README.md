# Bank Management System (C++)

A small console-based Bank Management System written in C++ and built with CMake. This repository contains the source, local header libraries, and sample data files used by the program. The project is organized for development using CMake and common command-line build tools (Ninja, Makefiles or the default generator on Windows).

## Quick summary

- Language: C++ (C++17 or later recommended)
- Build system: CMake
- Typical workflow: configure -> build -> run

## Repository layout

- `CMakeLists.txt` — top-level CMake configuration
- `main.cpp` — program entry point
- `local_libraries/` — project-specific header files used by the source
  - `branchl.h`, `datab.h`, `GUI.h`, `holderl.h`
- `data/` — runtime data files used by the program
  - `branches_data.txt`, `holders_data.txt`
- `cmake-build-debug/` — (generated) build directory created by CLion / CMake + Ninja in this workspace

## Prerequisites

- CMake (>= 3.10 recommended; repository used CMake 3.25+ in the build directory)
- A C++ compiler that supports C++17 (MSVC, MinGW-w64, GCC, or Clang)
- Ninja or another build tool (optional; CMake will select a default generator if you don't supply one)

On Windows with WSL or Git Bash (bash.exe) these commands will work well.

## Build instructions (recommended)

1. Create a fresh build directory and run CMake to generate build files:

```bash
# create an out-of-source build directory
mkdir -p build
cd build

# generate using the default generator (Ninja or Visual Studio depending on system)
cmake -S .. -B .

# build the project
cmake --build . --config Debug
```

Notes:

- If you prefer Ninja explicitly, run `cmake -G Ninja -S .. -B build`.
- If CLion already created `cmake-build-debug/`, you can build there instead: `cmake --build cmake-build-debug --config Debug`.

## Run the program

After a successful build, an executable will be created in the build directory. The exact name depends on the CMake target and platform. Common possibilities:

```bash
# Example run commands (adjust path/name as needed)
./build/main            # unix-like output name
./cmake-build-debug/main.exe  # Windows example (with bash)
./cmake-build-debug/Bank-Management-System.exe
```

If you don't see the executable, list the build directory to find the binary name:

```bash
ls -l build
ls -l cmake-build-debug
```

Then run the binary and follow the on-screen menu prompts.

## Data files

The program uses the files in the `data/` folder at runtime. These include:

- `data/branches_data.txt` — stores branch information
- `data/holders_data.txt` — stores account/holder information

When running the executable from the project root, the program expects to find the `data/` folder next to the binary or in the working directory. If you move the binary, keep `data/` with it or run from the project root.

## Local libraries and headers

This project contains small, local header files under `local_libraries/` that the source includes. They encapsulate branch- and holder-related logic plus GUI helpers.

Files:

- `local_libraries/branchl.h`
- `local_libraries/datab.h`
- `local_libraries/GUI.h`
- `local_libraries/holderl.h`

If you change these headers, re-run the build step.

## Common tasks / troubleshooting

- CMake generator mismatch: If CMake selects Visual Studio but you want Ninja, pass `-G Ninja` to `cmake`.
- Missing compiler: install Visual Studio Build Tools (MSVC), MinGW-w64, or use WSL with GCC/Clang.
- Permission errors when running the binary on Windows bash: prefix with `./` and ensure the file is executable.

## Contributing

Small improvements and bug fixes are welcome. Typical workflow:

1. Fork / create a local branch
2. Make changes
3. Build and test locally
4. Open a pull request describing your changes

If you add new data files, add small sample files to `data/` and document their format in the README.

## License

MIT License
