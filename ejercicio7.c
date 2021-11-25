/*
Version 1.0
Created by Diego Andres Ramirez Garcia on 25/11/2021
*/

#include<stdio.h>
#include<omp.h>
int main(){
  #pragma omp parallel
  {
    int i;
    printf("Hola Mundo\n");
    #pragma omp for
      for (i = 0; i < 10; i++){
          printf("Iteración: %d\n", i);
      }
  }
  printf("Adios\n");
  return 0;
}