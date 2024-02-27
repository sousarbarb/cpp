# hello_world

## Build

### g++

```sh
g++ main.cpp -o hello_world
```

**Note:** direct usage of `g++` shown here only for education purposes, all the
other projects will use generation-based build tools such as CMake to compile
and build the projects.

### cmake

```sh
mkdir build

# Linux
cmake -G "Unix Makefiles" -B build/

# Windows
cmake -G "Visual Studio 17 2022" -B build/
# if you want to specify the target platform, use -A <Win32|x64|ARM|ARM64>

cd build/
make
```

## Run

```sh
$ ./hello_world
Hello World!
```
