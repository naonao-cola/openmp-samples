#include <iostream>
using namespace std;
   
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            
            // 交换 arr[i] 和 arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // 将枢纽元素放置到正确的位置
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}
 
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // 获取分区后的枢纽位置
        int pivot_index = partition(arr, low, high);
        
        // 分别对枢纽左右两边的子数组进行递归排序
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 2, 7, 11, 18, 29, 33};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quicksort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}