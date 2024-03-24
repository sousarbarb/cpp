# string

## Build

```sh
# Linux
cmake -G "Unix Makefiles" -B build/

# Windows
cmake -G "Visual Studio 17 2022" -B build/
# if you want to specify the target platform, use -A <Win32|x64|ARM|ARM64>

cd build/
make
```

**Note:** you do not need to call every time the cmake command to generate the
Unix-style Makefiles. If the file structure of your project did not change, you
only need to call again the make command.

## Run

```sh
./string
```
