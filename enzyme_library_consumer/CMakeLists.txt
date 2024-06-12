cmake_minimum_required(VERSION 3.16)
project(my_proj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(mfem CONFIG REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC mfem::mfem)