#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#define SIZE (size_t)5e8
//#define SIZE 1000
void vectorFill(size_t n, double V[n])
{
    for(size_t i = 0; i < n; i++)
        V[i] = rand();   
}

void vectorPrint(size_t n, double V[n])
{
    for(size_t i = 0; i < n; i++)
    {
        printf("%lf |", V[i]);
    }
    printf("\n");
}

void vectorMultiply(size_t n, double V1[n], double V2[n],double R[n])
{
    for(size_t i = 0; i < n; i++)
    {
        R[i] = V1[i] * V2[i];
    }
}

int main()
{
    
    double *A, *B, *C;
    double start, end;
   
    A = (double *)malloc(sizeof(double)*SIZE);
    B = (double *)malloc(sizeof(double)*SIZE);
    C = (double *)malloc(sizeof(double)*SIZE);

    vectorFill(SIZE, A);
    vectorFill(SIZE, B);
    
    start = omp_get_wtime();

    vectorMultiply(SIZE, A,B,C); 
    
    end = omp_get_wtime();

    printf("result:n = %ld : %lf\n",SIZE,end - start);
    

    return 0;
}