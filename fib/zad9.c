#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

unsigned long long  fibb(long n)
{
    switch(n)
    {
        case 0:return 0;
        case 1:return 1;
        case 2:return 1;
    }
    long i,j;
		i=fibb(n-1);
		j=fibb(n-2);
    return i+j;
}    



unsigned long long  fib(long n)
{
    unsigned long long i,j;
    #pragma omp parallel
    {
        #pragma omp single
        {
	        #pragma omp task shared(i) 
		        if(n<38)
                    i=fibb(n-1);
                else
                    i=fib(n-1);
	        #pragma omp task shared(j) 
                if(n<38)
		            j=fibb(n-2);
                else
                    j=fib(n-2);
	        #pragma omp taskwait
        }
    }
    return i+j;
}    

int main(int argc, char*argv[])
{
    if(argc !=2)return 1;
    long n = atol(argv[1]);
    unsigned long long fi;
    double start, end;
    start = omp_get_wtime();

    fi = fib(n);
    
    end = omp_get_wtime();
    printf("%ld | %llu | %lfs\n",n, fi, end - start);
    return 0;
}