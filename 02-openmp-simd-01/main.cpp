#include <iostream>
#include <omp.h>
#include <chrono>

using namespace std::chrono;

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

void star_no_omp( double *a, double *b, double *c, int n, int *ioff )
{
    int i;
    for ( i = 0; i < n; i++ )
    {
        a[i] *= b[i] * c[i+ *ioff];
    }
}

void fill_random_1d_real(int n, double *arr) 
{
    for (int i = 0; i < n; ++i) 
    {
        arr[i] = rand() / ((double) RAND_MAX);
    }
}


int main(int, char**)
{
    printf("Hello, from SIMD.1c!\n");

    //获取cpu核心数量
    int num_procs = omp_get_num_procs();
    printf("number procs %d\n", num_procs);
    printf("--------------------------\n");

    //数据量
    int n = 32768;

    double* a = (double*)malloc(n *sizeof(double));
    double* b = (double*)malloc(n *sizeof(double));
    double* c = (double*)malloc(n *sizeof(double));

    //向量赋值
    fill_random_1d_real(n, a);
    fill_random_1d_real(n, b);
    fill_random_1d_real(n, c);

    //偏移量赋值
    int ioff = 0; 

    //开始计算时间
    steady_clock::time_point start = steady_clock::now();

    for (size_t i = 0; i < 32768* 16; i++)
    {
        //运算omp
        // star(a, b, c, n, &ioff);

        //运算 no omp
        star_no_omp(a, b, c, n, &ioff);
    }  

    //停止计算时间
    steady_clock::time_point end = steady_clock::now();

    //计算时间消耗
    duration<double> time_span = duration_cast<duration<double>>(end - start);

    //输出时间
    std::cout << "It took me " << time_span.count() << " seconds." << std::endl;

    //释放资源
    free(a);
    free(b);
    free(c);
}
