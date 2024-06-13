//%compiler: clang
//%cflags: -fopenmp

/*
* name: reduction.6
* type: C
* version:    omp_5.1
*/
#include <stdio.h>
#include <omp.h>

int main (void)
{
  int a, i;

  #pragma omp parallel shared(a) private(i)
  {
    #pragma omp masked
    a = 0;

    // To avoid race conditions, add a barrier here.
    #pragma omp barrier

    #pragma omp for reduction(+:a)
    for (i = 0; i < 100; i++) 
    {
        a += i;
        //printf("[Thread %d] I print my second message.\n", omp_get_thread_num());
    }

    // #pragma omp single
    // printf ("Sum is %d\n", a);
  }

  printf ("Sum is %d\n", a);

  return 0;
}