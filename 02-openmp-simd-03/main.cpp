#include <iostream>
#include <omp.h>
#include <chrono>

using namespace std::chrono;
/*
* @@name:	SIMD.3c
* @@type:	C
* @@compilable:	yes
* @@linkable:	no
* @@expect:	success
* @@version:	omp_4.0
*/
double work( double *a, double *b, size_t n )
{
   size_t i;
   double tmp, sum;
   sum = 0.0;
   #pragma omp simd private(tmp) reduction(+:sum)
   for (i = 0; i < n; i++) {
      tmp = a[i] + b[i];
      sum += tmp;
   }
   return sum;
}

double work_no_omp( double *a, double *b, size_t n )
{
   size_t i;
   double tmp, sum;
   sum = 0.0;
   //#pragma omp simd private(tmp) reduction(+:sum)
   for (i = 0; i < n; i++) {
      tmp = a[i] + b[i];
      sum += tmp;
   }
   return sum;
}

void fill_random_1d_real(size_t n, double *arr) 
{
    for (size_t i = 0; i < n; ++i) 
    {
        arr[i] = rand() / ((double) RAND_MAX);
    }
}

int main(int, char**)
{
    printf("Hello, from SIMD.3c!\n");

    //获取cpu核心数量
    int num_procs = omp_get_num_procs();
    printf("number procs %d\n", num_procs);
    printf("--------------------------\n");

    //数据量
    size_t n = 65536;

    double* a = (double*)malloc(n *sizeof(double));
    double* b = (double*)malloc(n *sizeof(double));

    //向量赋值
    fill_random_1d_real(n, a);
    fill_random_1d_real(n, b);

    //开始计算时间
    steady_clock::time_point start = steady_clock::now();

    for (size_t i = 0; i < 65536 *16; i++)
    {
        //运算omp
        double sum = work(a, b, n);

        //运算 no omp
        // double sum = work_no_omp(a, b, n);

        printf("%ld---%lf--------------------------\n", i, sum);
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
}
