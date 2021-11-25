/*
Version 1.0
Created by Diego Andres Ramirez Garcia on 24/11/2021
*/
#include<stdio.h>
#include<omp.h>
int main(){
  int tid,nth;
  #pragma omp parallel
  {
    tid = omp_get_thread_num();
    nth = omp_get_num_threads();
    printf("Hola mundo desde el hilo %d de un total de %d\n", tid, nth);
  }
  printf("Adios");
  return 0;
}