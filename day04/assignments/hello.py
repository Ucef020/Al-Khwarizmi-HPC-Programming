#hello.py
from mpi4py import MPI
comm = MPI.COMM_WORLD
rank = comm.Get_rank()
N=4
print ("hello world from process ", rank)
print (' Parallel execution of hello_world with',N,' process')
