cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 17)

project(tictactoe_cpp)

add_subdirectory(components)
add_subdirectory(logic)
add_subdirectory(visuals)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC components)
target_link_libraries(${PROJECT_NAME} PUBLIC logic)
target_link_libraries(${PROJECT_NAME} PUBLIC visuals)