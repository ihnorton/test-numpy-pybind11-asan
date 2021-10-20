#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <pybind11/numpy.h>


#include "numpy/ndarraytypes.h"

namespace py = pybind11;

#include <iostream>

int main(int, char** argv) {
  py::scoped_interpreter guard{}; // start the interpreter and keep it alive

  auto array = py::array_t<double>(10);

  auto arr_addr = (ptrdiff_t*)&array;
  auto py_array_obj = (ptrdiff_t*)(array.ptr());
  auto arr_data = (ptrdiff_t*)array.mutable_data();

  std::cout << "sizeof(PyArray_Object*): " << sizeof(PyArrayObject) << std::endl;
  std::cout << "addressOf(array) [the pybind11 object]: " << arr_addr << std::endl;
  std::cout << "&array.handle [the pyobject]: " << py_array_obj << std::endl;
  std::cout << "array.mutable_data(): " << arr_data << std::endl;

  std::cout << "diff: " <<  arr_data - py_array_obj << std::endl;
}