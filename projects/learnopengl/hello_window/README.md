# hello_window

## Setup

### GLFW

```sh
sudo apt install libglfw3 libglfw3-dev libglfw3-doc
```

### GLAD

1. Go to the GLAD web service ([url](https://glad.dav1d.de/))
2. Set the following options:
   - Language: C/C++
   - API:
     - gl: Version 3.3 (minimum at least, _future versions of OpenGL starting_
      _from 3.3 add extra useful features to OpenGL without changing OpenGL's_
      _core mechanics_)
   - Profile: Core
   - Set _Generate a loader_
3. Download the zip file and copy its contents to your include directory
4. Add the `glad.c` file to your project

## Build

```sh
# Linux
cmake -G "Unix Makefiles" -B build/

cd build/
make
```

## Run

```sh
./hello_window
```
