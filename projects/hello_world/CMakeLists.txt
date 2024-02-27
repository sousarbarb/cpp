# Definition of the minimum version of the CMake required to compile the project
# (3.8 is the minimum version for C++17)
cmake_minimum_required(VERSION 3.8)

# Set the name of the project
project(hello_world)



## Compile options dependent on which compiler is used
# Microsoft Visual C++ (MSVC)
if (MSVC)

  set(${PROJECT_NAME}_COMPILE_OPTIONS "/Wall;/std:c++17")

  # /Wall       displays all warnings displayed by /W4 and all other warnings
  #             that /W4 doesn't include
  # /std:c++17  C++17 standard requirement

else()

  set(${PROJECT_NAME}_COMPILE_OPTIONS "-Wall;-Wextra;-Wpedantic;-std=c++17")

  # -Wall       enables all the warnings about constructions that some users
  #             consider questionable, and that are easy to avoid (or modify to
  #             prevent the warning), even in conjunction with macros.
  # -Wextra     enables some extra warning flags that are not enabled by -Wall
  # -Wpedantic  issue all the warnings demanded by strict ISO C and ISO C++
  # -std=c++17  C++17 standard requirement

endif()



# add an executable to the CMake project
# - ${PROJECT_NAME}   sets the name of the executable as the same
# - main.cpp          file that belongs to the desirable executable
add_executable(${PROJECT_NAME}
  main.cpp
)

# target specific compilation options (safest way currently in cmake!)
# (use this instead of set(CMAKE_CXX_STANDARD 17), etc...)
target_compile_options(${PROJECT_NAME} PRIVATE
  ${${PROJECT_NAME}_COMPILE_OPTIONS}
)
