 
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
    long n = 100;
    long *arr = (long*)malloc(sizeof(long)* n);

    // 初始化数据
    fill_random_1d(n, arr);

    //Explicitly disable dynamic teams
    //omp_set_dynamic(0);             

    //Use N threads for all parallel regions
    //omp_set_num_threads(16); 

    // clock start
    p_SteadyClock->Start();

	quickSort(arr,0,n-1);

    // clock end
    p_SteadyClock->End();
    p_SteadyClock->Duration("quicksort one thread");

    
    for (long i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    

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