cmake_minimum_required(VERSION 3.00)
project(MovingDot)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_CXX_STANDARD 17)

add_executable(MovingDot src/main.cpp src/Game.cpp src/Game.h src/Graphics.cpp src/Graphics.h)
target_link_libraries(MovingDot mingw32)
target_link_libraries(MovingDot SDL2main)
target_link_libraries(MovingDot SDL2)