cmake_minimum_required(VERSION 3.8)

project(hello_triangle)



set(${PROJECT_NAME}_COMPILE_OPTIONS "-Wall;-Wextra;-std=c++17")



find_package(glfw3 3.3 REQUIRED)



add_executable(${PROJECT_NAME}
  src/glad.c
  src/main.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE
  ${${PROJECT_NAME}_COMPILE_OPTIONS}
)

target_include_directories(${PROJECT_NAME} PRIVATE
  include
)

target_link_libraries(${PROJECT_NAME}
  ${CMAKE_DL_LIBS}  # required to link the dl libraries to your target (GLAD)
  glfw
)
