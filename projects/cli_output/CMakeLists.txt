cmake_minimum_required(VERSION 3.8)

project(cli_output)



if (MSVC)
  set(${PROJECT_NAME}_COMPILE_OPTIONS "/Wall;/std:c++17")
else()
  set(${PROJECT_NAME}_COMPILE_OPTIONS "-Wall;-Wextra;-Wpedantic;-std=c++17")
endif()



add_executable(${PROJECT_NAME}
  main.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE
  ${${PROJECT_NAME}_COMPILE_OPTIONS}
)
