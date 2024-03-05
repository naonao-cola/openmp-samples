#include <stdio.h>
#include <omp.h>

int main() 
{
    //获取cpu核心数量
    int num_procs = omp_get_num_procs();
    printf("number procs %d\n", num_procs);
    printf("--------------------------\n");

    //获取cpu运行线程数量
    // int num_threads = omp_get_num_threads();
    // printf("number threads %d\n", num_threads);

   #pragma omp parallel num_threads(num_procs*2)
   {
        // //获取cpu运行线程数量
        // int num_threads = omp_get_num_threads();
        // printf("number threads %d\n", num_threads);

        int idx = omp_get_thread_num();
        printf("Hello from thread %d\n", idx);
   }

    return 0;
}