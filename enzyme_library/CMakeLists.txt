cmake_minimum_required(VERSION 3.16)
project(my_proj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Enzyme CONFIG REQUIRED)

add_library(mfem mfem.cpp)
target_link_libraries(mfem PUBLIC ClangEnzymeFlags)

target_include_directories(mfem PUBLIC
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

set(MFEM_ENZYME_DIR ${ENZYME_DIR})

configure_file(mfemConfig.cmake.in mfemConfig.cmake @ONLY)

install(TARGETS mfem
    EXPORT mfem-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)

install(EXPORT mfem-targets
  FILE
    mfemTargets.cmake
  NAMESPACE
    mfem::
  DESTINATION
    "${CMAKE_INSTALL_PREFIX}/cmake/mfem"
)

install(FILES
    ${PROJECT_SOURCE_DIR}/mfem.hpp
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)

install(FILES
    ${CMAKE_BINARY_DIR}/mfemConfig.cmake
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake/mfem
)