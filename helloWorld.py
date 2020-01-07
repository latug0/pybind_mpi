#!/usr/bin/python3

import mpi4py
from  mpi4py  import  MPI
import numpy as np
from mpi_lib import Distributed

def  main ():
    comm =   MPI.COMM_WORLD
    rank = comm.Get_rank ()
    size = comm.Get_size ()
    name = MPI.Get_processor_name()
    print("Hello  from " + name + " which is rank " + str( rank ) + " in " + str( size ))
    distrib = Distributed(comm)
    distrib.say_hi()

if  __name__  == "__main__":
    main()
