 
#include <iostream>
#include  <omp.h>

#include"SteadyClock.h"

void quickSort(long *num,long low,long high);//进行分区
long Partition(long *num,long low,long high);//返回分离点

void fill_random_1d(long n, long *arr) 
{
    for (long i = 0; i < n; ++i) 
    {
        arr[i] = rand();
    }
}

int main()
{
    // clock init
    SteadyClock* p_SteadyClock = new SteadyClock();
    p_SteadyClock->Init();

    // 创建数据源
    long n = 1e8;
    long *arr = (long*)malloc(sizeof(long)* n);

    // 初始化数据
    fill_random_1d(n, arr);

    //num_threads
    int num_threads = 8;

    //Explicitly disable dynamic teams
    //omp_set_dynamic(0);             

    //Use N threads for all parallel regions
    omp_set_num_threads(num_threads); 

    // clock start
    p_SteadyClock->Start();

    #pragma omp parallel
    {
        #pragma omp single
	    quickSort(arr,0,n-1);
    }
    // clock end
    p_SteadyClock->End();

    printf("%d num_threads", num_threads);
    p_SteadyClock->Duration("quicksort ");

    // Check if the array is sorted
    for (int i = 0; i < n - 1; i++)
    {
        // printf("Array index: %d \n", i);
        if (arr[i] > arr[i + 1])
        {
            printf("Error: arr is not sorted!\n");
            return 1;
        }
    }

	return 0;
}
 
 
void quickSort(long *num,long low,long high)
{
	if(low<high)
	{
		long split=Partition(num,low,high);
        //并行区域
		{
            #pragma omp task//负责这个区域的线程对前面部分进行排序
		    quickSort(num,low,split-1);

            #pragma omp task//负责这个区域的线程对后面部分进行排序
		    quickSort(num,split+1,high);
		}
 
	}
 
}
 
long Partition(long *num,long low,long high)
{
	long temp=num[low];//作为中轴
	while(low<high)
	{
		while(low<high&&num[high]>=temp)high--;
		num[low]=num[high];
		while(low<high&&num[low]<=temp)low++;
		num[high]=num[low];
	}
	num[low]=temp;
	return low;//返回中轴的位置，再进行分离
}