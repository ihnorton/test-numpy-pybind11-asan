project(nptest)

set(CMAKE_BUILD_TYPE Debug)

cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_STANDARD 17)

### numpy
find_package (Python COMPONENTS Interpreter Development.Embed NumPy REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

### pybind11
find_package(pybind11 REQUIRED HINTS $ENV{CONDA_PREFIX})

add_executable(main main.cc)
target_link_libraries(main PRIVATE Python::NumPy)
target_link_libraries(main PRIVATE Python::Python)
target_link_libraries(main PRIVATE pybind11::embed)

if(FALSE)
target_compile_options(main
    PRIVATE
    #-g -fno-omit-frame-pointer -fno-optimize-sibling-calls -fsanitize=address
    -g -fsanitize=address
)
target_link_options(
    main
    PRIVATE
    -fsanitize=address
)
endif()