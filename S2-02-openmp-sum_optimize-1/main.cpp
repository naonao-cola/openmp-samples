//%compiler: clang
//%cflags: -fopenmp

/*
* name: reduction.6
* type: C
* version:    omp_5.1
*/
#include <stdio.h>
#include <omp.h>
#include <math.h>

#include"SteadyClock.h"

void fill_random_1d(size_t n, size_t *arr) 
{
    for (size_t i = 0; i < n; ++i) 
    {
        arr[i] = rand();
    }
}

int main (void)
{
    // clock init
    SteadyClock* p_SteadyClock = new SteadyClock();
    p_SteadyClock->Init();

    // 创建数据源
    size_t n = 1e9, sum = 0;
    size_t *arr = (size_t*)malloc(sizeof(size_t)* n);

    // 初始化数据
    fill_random_1d(n, arr);

    //单线程 sum
    //////////////////////////////////////////////////////////

    // clock start
    p_SteadyClock->Start();

    //sum one thread
    for (size_t i = 0; i < n; i++) 
    {
        sum += arr[i];
    }

    // clock end
    p_SteadyClock->End();
    p_SteadyClock->Duration("sum one thread");

    //输出结果
    printf ("Sum[sum one thread] is %ld\n", sum);

    //多线程omp sum
    //////////////////////////////////////////////////////////

    // clock start
    p_SteadyClock->Start();

    #pragma omp parallel shared(n, arr)
    {
        #pragma omp masked
        sum = 0;

        // To avoid race conditions, add a barrier here.
        #pragma omp barrier

        #pragma omp for reduction(+:sum)
        for (size_t i = 0; i < n; i++) 
        {
            sum += arr[i];
            //printf("[Thread %d] I print my second message.\n", omp_get_thread_num());
        }

        // #pragma omp single
        // printf ("Sum is %d\n", a);
    }

    // clock end
    p_SteadyClock->End();
    p_SteadyClock->Duration("sum omp thread");

    //输出结果
    printf ("Sum[sum omp thread] is %ld\n", sum);

    //释放资源
    free(arr);

    // clock release
    p_SteadyClock->Release();
    delete p_SteadyClock;
  
    return 0;
}