# Simple example that exhibits the use of pybind11, MPI and mpi4py

## Introduction

Demonstrates how to call a C++ class from Python using pybind11 together with MPI.

Derived from the following URLs:
* https://coderefinery.github.io/mma/03-pybind11/
* https://stackoverflow.com/questions/49259704/pybind11-possible-to-use-mpi4py/50022979
* https://lipn.univ-paris13.fr/~coti/doc/tutopympi.pdf

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
cmake ..
make
```

## Example test run

```
mpirun -n 8 python3 helloWorld.py
 Hello  from skylake109.cluster which is rank 0 in 8
 Hello  from skylake109.cluster which is rank 1 in 8
 Hello  from skylake110.cluster which is rank 3 in 8
 Hello  from skylake110.cluster which is rank 2 in 8
 Hello  from skylake112.cluster which is rank 6 in 8
 Hello  from skylake112.cluster which is rank 7 in 8
 Hello  from skylake111.cluster which is rank 5 in 8
 Hello  from skylake111.cluster which is rank 4 in 8
 Hi from processor skylake110.cluster, rank 3 out of 8 processors
 Hi from processor skylake110.cluster, rank 2 out of 8 processors
 Hi from processor skylake109.cluster, rank 0 out of 8 processors
 Hi from processor skylake109.cluster, rank 1 out of 8 processors
 Hi from processor skylake112.cluster, rank 6 out of 8 processors
 Hi from processor skylake112.cluster, rank 7 out of 8 processors
 Hi from processor skylake111.cluster, rank 5 out of 8 processors
 Hi from processor skylake111.cluster, rank 4 out of 8 processors
```
