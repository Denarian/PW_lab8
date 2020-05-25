#include <stdio.h>
#include <omp.h>
int a;
void shared(){
    int i;
    printf("Parallel share start[a=%d]:\n",a);
    #pragma omp parallel for shared(a) num_threads(7)
    for(i=0;i<10;i++)
	{
        printf("Thread %d a=%d\n",omp_get_thread_num(),a);
        ++a;
	}
    printf("a=%d\n",a);
}
void firstPrivate(){
    int i;
    printf("Parallel firstPrivate start[a=%d]:\n",a);
    #pragma omp parallel for firstprivate(a) num_threads(7)
    for(i=0;i<10;i++)
	{
        printf("Thread %d a=%d\n",omp_get_thread_num(),a);
        ++a;
	}
    printf("a=%d\n",a);
    
}
void private(){
    int i;
    printf("Parallel private start[a=%d]:\n",a);
    #pragma omp parallel for private(a) num_threads(7)
    for(i=0;i<10;i++)
	{
        //uninitialized a
        printf("Thread %d a=%d\n",omp_get_thread_num(),a);
        ++a;
	}
    printf("a=%d\n",a);
}

int main() {
	a = 7;
    shared();
    a = 7;
    firstPrivate();
    a = 7;
    private();
    // #pragma omp parallel for num_threads(7)
	// for(i=0;i<10;i++)
	// {
	//      printf("Thread %d a=%d\n",omp_get_thread_num(),a);
	//          a++;
	// }
	// return 0;
}