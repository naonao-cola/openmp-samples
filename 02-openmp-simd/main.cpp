#include <iostream>
#include <omp.h>

/*
* @@name:	SIMD.1c
* @@type:	C
* @@compilable:	yes
* @@linkable:	no
* @@expect:	success
* @@version:	omp_4.0
*/
void star( double *a, double *b, double *c, int n, int *ioff )
{
    int i;
    #pragma omp simd
    for ( i = 0; i < n; i++ )
    {
        a[i] *= b[i] * c[i+ *ioff];
    }
    
}

int main(int, char**)
{
    std::cout << "Hello, from SIMD.1c!\n";

        //获取cpu核心数量
    int num_procs = omp_get_num_procs();
    printf("number procs %d\n", num_procs);
    printf("--------------------------\n");

    //数据量
    int n = 65536;


}
