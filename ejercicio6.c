/*
Version 2.0
Created by Diego Andres Ramirez Garcia on 24/11/2021
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>
#define n 10

void llenarArreglo(int *a);
void suma(int *a, int *b, int*c);

int main(){
  int max, *a, *b, *c;
  a = (int*)malloc(sizeof(int)*n);
  b = (int*)malloc(sizeof(int)*n);
  c = (int*)malloc(sizeof(int)*n);

  llenarArreglo(a);
  llenarArreglo(b);

  suma(a,b,c);
}

void llenarArreglo(int *a){
  int i;
  for(i=0;i < n;i++){
    a[i] = rand()%n;
    printf("%d\t", a[i]);
  }
  printf("\n");
}

void suma(int *A,int *B,int *C){
  int i,tid,inicio,fin;
  omp_set_num_threads(2);
  #pragma omp parallel private(i,tid,inicio,fin)
  {
    tid = omp_get_thread_num();
    inicio = tid*5;
    fin = (tid+1)*5-1;
    
    for(i = inicio; i <= fin; i++){
      C[i] = A[i] + B[i];
      printf("hilo %d calculo C[%d] = %d\n", tid,i,C[i]);
    }
  }

  for(i = 0;i < n; i++){
    printf("%d\t", C[i]);
  }
}