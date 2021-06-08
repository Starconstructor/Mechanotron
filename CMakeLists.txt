cmake_minimum_required(VERSION 3.10)

project(Mechanotron)

add_executable(Mechanotron Mechanotron.c)

target_link_libraries(Mechanotron -lglfw)
target_link_libraries(Mechanotron -lvulkan)
target_link_libraries(Mechanotron -ldl)
target_link_libraries(Mechanotron -lpthread)
target_link_libraries(Mechanotron -lX11)
target_link_libraries(Mechanotron -lXxf86vm)
target_link_libraries(Mechanotron -lXrandr)
target_link_libraries(Mechanotron -lXi)
