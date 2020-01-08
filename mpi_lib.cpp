#include <mpi.h>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <stdio.h>

namespace py = pybind11;
using pymod = pybind11::module;

class Distributed
{
public:
  Distributed() : comm_global(MPI_COMM_WORLD) {}
  
  ~Distributed() {}
  
  void say_hi() {
    int world_size;
    MPI_Comm_size(comm_global, &world_size);
    int world_rank;
    MPI_Comm_rank(comm_global, &world_rank);
    char processor_name[MPI_MAX_PROCESSOR_NAME] = "localhost";
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
    printf("[C++]    Hello from machine %s, MPI rank %d out of %d\n",
	   processor_name,
	   world_rank,
	   world_size);
  }
  
private:
  MPI_Comm comm_global;
};



PYBIND11_MODULE(mpi_lib, mmod)
{
  constexpr auto MODULE_DESCRIPTION = "Just testing out mpi with python.";
  mmod.doc() = MODULE_DESCRIPTION;
  
  py::class_<Distributed>(mmod, "Distributed")    
    //    .def(py::init<py::object &>())
    .def(py::init<>())
    .def("say_hi", &Distributed::say_hi, "Each process will say hi");
  
}
