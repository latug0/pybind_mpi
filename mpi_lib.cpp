#include <mpi.h>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <stdio.h>

namespace py = pybind11;
using pymod = pybind11::module;

class Distributed
{
    public:
        Distributed(py::object &pycomm) {
	  pymod pyMPI = pymod::import("mpi4py.MPI");
	  comm = *reinterpret_cast<MPI_Comm*>(pyMPI.attr("_addressof")(pycomm).cast<uintptr_t>());
		
	}

        ~Distributed() {}

        void say_hi() {
	  int world_size;
	  MPI_Comm_size(comm, &world_size);
	  int world_rank;
	  MPI_Comm_rank(comm, &world_rank);
	  char processor_name[MPI_MAX_PROCESSOR_NAME] = "localhost";
	  int name_len;
	  MPI_Get_processor_name(processor_name, &name_len);
	  printf("Hi from processor %s, rank %d out of %d processors\n",
		 processor_name,
		 world_rank,
		 world_size);
	}

    private:
        MPI_Comm comm;
};



PYBIND11_MODULE(mpi_lib, mmod)
{
    constexpr auto MODULE_DESCRIPTION = "Just testing out mpi with python.";
    mmod.doc() = MODULE_DESCRIPTION;

    py::class_<Distributed>(mmod, "Distributed")    
      .def(py::init<py::object &>())
      .def("say_hi", &Distributed::say_hi, "Each process will say hi");

}
