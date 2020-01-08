# Example for using C++ library, pybind11, mpi4py & MPI

## Introduction

Demonstrates how to call a C++ class from Python using pybind11 together with MPI.

To fetch this repository use the following command:
```
git clone --recursive https://codev-tuleap.cea.fr/plugins/git/helix/test_pybind_mpi.git
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
spack install py-mpi4py
spack install py-numpy
spack install openmpi
spack install cmake@3.12.4
```

Each time you want to use the installed package, you will do:
```
spack load -r py-mpi4py
spack load -r py-numpy
spack load -r openmpi
spack load -r cmake@3.12.4
```

## How to build this demo

```
git clone --recursive https://codev-tuleap.cea.fr/plugins/git/helix/test_pybind_mpi.git
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
mpirun -n 8 python3 -m mpi4py helloWorld.py
[Python] Hello from machine skylake109.cluster, MPI rank 0 out of 8
[Python] Hello from machine skylake109.cluster, MPI rank 1 out of 8
[Python] Hello from machine skylake110.cluster, MPI rank 2 out of 8
[Python] Hello from machine skylake110.cluster, MPI rank 3 out of 8
[Python] Hello from machine skylake111.cluster, MPI rank 4 out of 8
[Python] Hello from machine skylake111.cluster, MPI rank 5 out of 8
[Python] Hello from machine skylake112.cluster, MPI rank 6 out of 8
[Python] Hello from machine skylake112.cluster, MPI rank 7 out of 8
[C++]    Hello from machine skylake109.cluster, MPI rank 0 out of 8
[C++]    Hello from machine skylake109.cluster, MPI rank 1 out of 8
[C++]    Hello from machine skylake110.cluster, MPI rank 2 out of 8
[C++]    Hello from machine skylake110.cluster, MPI rank 3 out of 8
[C++]    Hello from machine skylake111.cluster, MPI rank 4 out of 8
[C++]    Hello from machine skylake111.cluster, MPI rank 5 out of 8
[C++]    Hello from machine skylake112.cluster, MPI rank 6 out of 8
[C++]    Hello from machine skylake112.cluster, MPI rank 7 out of 8
```
