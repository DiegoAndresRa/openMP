/*
Version 1.4
Created by Diego Andres Ramirez Garcia on 24/11/2021
*/

#include<stdio.h>
#include<omp.h>
int main(){
    int i;
    #pragma omp parallel
    {
        printf("Hola Mundo\n");
        for (i = 0; i < 10; i++)
            printf("Iteración: %d\n", i);
    }
    printf("Adios\n");
    return 0;
}