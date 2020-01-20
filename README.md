# Example for using C++ library, pybind11, mpi4py & MPI

## Introduction

Demonstrates how to call a C++ class from Python using pybind11 together with MPI.

To fetch this repository use the following command:
```
git clone --recursive https://codev-tuleap.cea.fr/plugins/git/helix/test_pybind_mpi.git
```
or
```
git clone https://codev-tuleap.cea.fr/plugins/git/helix/test_pybind_mpi.git
git submodule init
git submodule update --init
```

Derived from the following URLs:

- https://coderefinery.github.io/mma/03-pybind11
- https://stackoverflow.com/questions/49259704/pybind11-possible-to-use-mpi4py/50022979
- https://lipn.univ-paris13.fr/~coti/doc/tutopympi.pdf
- https://mpi4py.readthedocs.io/en/stable/mpi4py.run.html

## Contents
 
Main files:

- `mpi_lib.cpp`: C++/MPI library code
- `helloWorld.py`: python code that call the C++/MPI library (using pybind11 and mpi4py)

## How to configure your system

An easy way to setup the needed package is to use 'spack' machinery.
```
git clone https://github.com/spack/spack
source spack/share/spack/setup-env.sh # you should also put this line into you .bashrc
spack install openmpi
spack install python@3.7.4
spack install py-mpi4py
spack install py-numpy
spack install cmake@3.12.4
```

Each time you want to use the installed package, you will do:
```
spack load -r openmpi
spack load python@3.7.4
spack load -r py-mpi4py
spack load -r py-numpy
spack load -r cmake@3.12.4
```

Another way to go without spack for a quicker installation (however requiring root user access) can be:
```
apt install openmpi
apt install python3
apt install cmake
pip3 install numpy
pip3 install https://bitbucket.org/mpi4py/mpi4py/get/master.tar.gz
```


## How to build this demo

```
cd test_pybind_mpi
mkdir build
cd build
export CC=<my C compiler>
export CXX=<my C++ compiler>
cmake ..
make
```

## Example test run

```
mpirun -n 8 python3 helloWorld.py
[Python] Hello from machine skylake095.cluster, MPI rank 3 out of 8
[C++]    Hello from machine skylake095.cluster, MPI rank 3 out of 8
[Python] Hello from machine skylake095.cluster, MPI rank 2 out of 8
[C++]    Hello from machine skylake095.cluster, MPI rank 2 out of 8
[Python] Hello from machine skylake090.cluster, MPI rank 1 out of 8
[C++]    Hello from machine skylake090.cluster, MPI rank 1 out of 8
[Python] Hello from machine skylake099.cluster, MPI rank 5 out of 8
[C++]    Hello from machine skylake099.cluster, MPI rank 5 out of 8
[Python] Hello from machine skylake099.cluster, MPI rank 4 out of 8
[C++]    Hello from machine skylake099.cluster, MPI rank 4 out of 8
[Python] Hello from machine skylake100.cluster, MPI rank 6 out of 8
[C++]    Hello from machine skylake100.cluster, MPI rank 6 out of 8
[Python] Hello from machine skylake100.cluster, MPI rank 7 out of 8
[C++]    Hello from machine skylake100.cluster, MPI rank 7 out of 8
[Python] Hello from machine skylake090.cluster, MPI rank 0 out of 8
[C++]    Hello from machine skylake090.cluster, MPI rank 0 out of 8
Detected thread level MPI_THREAD_FUNNELED
Hello World from thread = 0
Hello World from thread = 5
Hello World from thread = 4
Hello World from thread = 10
Hello World from thread = 1
Hello World from thread = 2
Hello World from thread = 13
Hello World from thread = 3
Hello World from thread = 11
Hello World from thread = 8
Hello World from thread = 9
Hello World from thread = 6
Hello World from thread = 14
Hello World from thread = 7
Hello World from thread = 12
Hello World from thread = 15
Number of threads = 16
```
