#include <iostream>
#include"SteadyClock.h"

using namespace std;
   
long partition(long arr[], long low, long high) {
    long pivot = arr[high];
    long i = (low - 1);
    
    for (long j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            
            // 交换 arr[i] 和 arr[j]
            long temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // 将枢纽元素放置到正确的位置
    long temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}
 
void quicksort(long arr[], long low, long high) {
    if (low < high) {
        // 获取分区后的枢纽位置
        long pivot_index = partition(arr, low, high);
        
        // 分别对枢纽左右两边的子数组进行递归排序
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

void fill_random_1d(long n, long *arr) 
{
    for (long i = 0; i < n; ++i) 
    {
        arr[i] = rand() % 10;
    }
}

int main() 
{
    // clock init
    SteadyClock* p_SteadyClock = new SteadyClock();
    p_SteadyClock->Init();

    // 创建数据源
    long n = 1e6;
    long *arr = (long*)malloc(sizeof(long)* n);

    // 初始化数据
    fill_random_1d(n, arr);
        
    // clock start
    p_SteadyClock->Start();

    quicksort(arr, 0, n - 1);

    // clock end
    p_SteadyClock->End();
    p_SteadyClock->Duration("quicksort one thread");
    
    /*
    for (long i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    */
   
    // clock release
    p_SteadyClock->Release();
    delete p_SteadyClock;

    return 0;
}