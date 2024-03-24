# cli_output

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

## Run

```sh
./cli_output
```
