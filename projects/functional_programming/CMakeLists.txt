cmake_minimum_required(VERSION 3.8)

project(functional_programming)



if (MSVC)
  set(${PROJECT_NAME}_COMPILE_OPTIONS "/Wall;/std:c++17")
else()
  set(${PROJECT_NAME}_COMPILE_OPTIONS "-Wall;-Wextra;-Wpedantic;-std=c++17")
endif()



## declare the cpp files of the header's implementation functions
## or if you want to declare a library, use add_library and link it later to
## your executable
add_executable(${PROJECT_NAME}
  src/simple_math.cpp
  src/main.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE
  ${${PROJECT_NAME}_COMPILE_OPTIONS}
)

## required to tell the compiler the include directories of your target
target_include_directories(${PROJECT_NAME} PRIVATE
  src/
)
