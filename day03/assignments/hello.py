from pyccel.stdlib.internal.openmp import omp_set_num_threads
from pyccel.decorators import types
from pyccel.stdlib.internal.openmp import omp_set_num_threads, omp_get_num_threads, omp_get_thread_num
@types('int')
def get_num_threads(n):
   omp_set_num_threads(n)
   #$ omp parallel
   print("Hello from the rank ", omp_get_thread_num()," thread")
   result = omp_get_num_threads()
   #$ omp end parallel
   return result

if __name__ == "__main__" :
   x = get_num_threads(6)
   print("parallel execution of hello_world with ",x , "threads")
