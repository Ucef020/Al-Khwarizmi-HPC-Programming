#include<stdio.h>
#include<time.h>
#include <stdlib.h>
int main (){
 
  int max_stride = 30;
  int N = 1000000,i_stride;
  //float *p = malloc(sizeof(int));
  double * a;
  a = (double *)malloc(max_stride * N * sizeof(double));
  //float a[N * max_stride];
  double rt[40];
  double cpu[40];
  double mean, msec,rate;


   
    for (int i = 0; i < N * max_stride;i++){
       a[i] = 0;
    }

    for(i_stride = 1; i_stride <= max_stride; i_stride++){

      mean = 0.0;
      // getting starting time
      clock_t begin = clock();

      for (int i=0; i< N * i_stride; i+=i_stride){
        mean = mean + a[i];
      }

      //getting end time;
      clock_t end = clock();
      // Cpu_Time
      msec = end - begin;
      // Bande_passante
      rate = 8 * N * (1000.0/msec) / (1024*1024);
      printf("-----------------------------------------\n\n");
      printf("i_stride = %d\nmean = %f\nCPU_Time = %f\nrate = %f\n", i_stride,mean,msec,rate);
      rt[i_stride-1] = rate;
      cpu[i_stride-1] = msec;

    }
    printf("Y = [");
    for(i_stride = 1; i_stride <= max_stride; i_stride++){
    printf("%f,",rt[i_stride-1]);
}
printf("] \nY1 = [");
for(i_stride = 1; i_stride <= max_stride; i_stride++){
    printf("%f,",cpu[i_stride-1]);
}
printf("]");
    return 0;

}
