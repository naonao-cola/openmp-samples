#include <iostream>
#include <omp.h>
#include <chrono>

using namespace std::chrono;

/*
* @@name:	SIMD.4c
* @@type:	C
* @@compilable:	yes
* @@linkable:	no
* @@expect:	success
* @@version:	omp_4.0
*/
void work( float *b, int n, int m )
{
    int i;
    #pragma omp simd safelen(16)
    for (i = m; i < n; i++)
        b[i] = b[i-m] - 1.0f;
}

void work_no_omp( float *b, int n, int m )
{
    int i;
    // #pragma omp simd safelen(16)
    for (i = m; i < n; i++)
        b[i] = b[i-m] - 1.0f;
}

void fill_random_1d_real(int n, float *arr) 
{
    for (int i = 0; i < n; ++i) 
    {
        arr[i] = rand() / ((float) RAND_MAX);
    }
}


int main(int, char**)
{
    printf("Hello, from SIMD.4c!\n");

    //获取cpu核心数量
    int num_procs = omp_get_num_procs();
    printf("number procs %d\n", num_procs);
    printf("--------------------------\n");

    //数据量
    int n = 32768;

    float* b = (float*)malloc(n *sizeof(float));

    //向量赋值
    fill_random_1d_real(n, b);


    //开始计算时间
    steady_clock::time_point start = steady_clock::now();

    for (size_t i = 0; i < 32768* 64; i++)
    {
        //运算omp
        work(b, n, 16);

        //运算 no omp
        // work_no_omp(b, n, 16);

        //输出一个值
        printf("%ld---%lf-----------------------\n", i, b[128]);
    }  

    //停止计算时间
    steady_clock::time_point end = steady_clock::now();

    //计算时间消耗
    duration<double> time_span = duration_cast<duration<double>>(end - start);

    //输出时间
    std::cout << "It took me " << time_span.count() << " seconds." << std::endl;

    //释放资源
    free(b);
}
