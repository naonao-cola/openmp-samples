#include <iostream>
#include <omp.h>
#include <chrono>

using namespace std::chrono;

/*
* @@name:	SIMD.5c
* @@type:	C
* @@compilable:	yes
* @@linkable:	no
* @@expect:	success
* @@version:	omp_4.0
*/
void work( double **a, double **b, double **c, int n )
{
   int i, j;
   double tmp;
   #pragma omp for simd collapse(2) private(tmp)
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         tmp = a[i][j] + b[i][j];
         c[i][j] = tmp;
      }
   }
}

void work_no_omp( double **a, double **b, double **c, int n )
{
   int i, j;
   double tmp;
//    #pragma omp for simd collapse(2) private(tmp)
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         tmp = a[i][j] + b[i][j];
         c[i][j] = tmp;
      }
   }
}

void fill_random_2d_real(int n, double** arr) 
{
    for (size_t i = 0; i < n; ++i) 
    {
        for (size_t j = 0; j < n; ++j) 
        {
            arr[i][j] = rand() / ((float) RAND_MAX);
        }
    }
}

int main(int, char**)
{
    printf("Hello, from SIMD.5c!\n");

    //获取cpu核心数量
    int num_procs = omp_get_num_procs();
    printf("number procs %d\n", num_procs);
    printf("--------------------------\n");

    //数据量
    int n = 8192;

    double** a = (double**)malloc(n *sizeof(double*)); 
    double** b = (double**)malloc(n *sizeof(double*));
    double** c = (double**)malloc(n *sizeof(double*));

    for (size_t i = 0; i < n; i++)
    {
        a[i] = (double*)malloc(n *sizeof(double)); 
        b[i] = (double*)malloc(n *sizeof(double)); 
        c[i] = (double*)malloc(n *sizeof(double)); 
    }

    fill_random_2d_real(n, a);
    fill_random_2d_real(n, b);
    fill_random_2d_real(n, c);
    

    //开始计算时间
    steady_clock::time_point start = steady_clock::now();

    for (size_t i = 0; i < 1024; i++)
    {
        //运算omp
        // work(a, b, c, n);

        //运算 no omp
        work_no_omp(a, b, c, n);

        //输出一个值
        printf("%ld---%lf-----------------------\n", i, c[128][128]);
    }  

    //停止计算时间
    steady_clock::time_point end = steady_clock::now();

    //计算时间消耗
    duration<double> time_span = duration_cast<duration<double>>(end - start);

    //输出时间
    std::cout << "It took me " << time_span.count() << " seconds." << std::endl;

    //释放资源

    for(size_t i =0; i <n; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }

    free(a);
    free(b);
    free(c);
}
