#!/usr/bin/env python3

import mpi4py
mpi4py.rc.threaded = True
mpi4py.rc.thread_level = "funneled"
from mpi4py  import  MPI
from mpi_lib import Distributed

# Main program that delegates some work to a C++/MPI routine: say_hi
def  main ():
    comm =   MPI.COMM_WORLD
    rank = comm.Get_rank ()
    size = comm.Get_size ()
    name = MPI.Get_processor_name()
    print("[Python] Hello from machine " + name + ", MPI rank " + str( rank ) + " out of " + str( size ))
    distrib = Distributed()
    distrib.say_hi()

if  __name__  == "__main__":
    main()
