cmake_minimum_required(VERSION 2.8.12)
project(example)

find_package(PythonLibs)
include_directories(${PYTHON_INCLUDE_DIRS})


find_package(MPI REQUIRED)
set(CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
set(CMAKE_CXX_LINK_FLAGS ${CMAKE_CXX_LINK_FLAGS} ${MPI_LINK_FLAGS})
include_directories(${MPI_INCLUDE_PATH})

add_subdirectory(pybind11)
pybind11_add_module(mpi_lib mpi_lib.cpp)
target_link_libraries(mpi_lib PRIVATE mpi)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/helloWorld.py
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

