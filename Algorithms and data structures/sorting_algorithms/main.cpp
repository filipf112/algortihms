#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

int *tmp;

void merge (int arr[], int left, int mid, int right){
    int i = left, j = mid + 1;

    for(int i = left; i <=right; i++){
        tmp[i] = arr[i];
    }

    for (int k = left; k <=right; k++){
        if (i<=mid)
            if (j<=right)
                if(arr[j]<tmp[i])
                    arr[k] = tmp[j++];
                else
                    arr[k] = tmp[i++];
            else
                arr[k] = tmp[i++];
        else
            arr[k] = tmp[j++];

    }
}

void merge_sort(int arr[], int left, int right){
    if (right<=left) return;

    int mid = (right+left)/2;

    merge_sort(arr,left,mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, left,mid,right);
}

void insertion_sort(int n, int *arr){
    int tmp, j;
    for (int i = 1; i < n;i++){
        tmp = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>tmp){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = tmp;
    }
}

void heapify(int arr[], int N, int i)
{
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i > 0; i--) {

        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void quick_sort(int *arr, int left, int right)
{
    if(right <= left) return;

    int i = left - 1, j = right + 1,
            pivot = arr[(left+right)/2];

    while(1)
    {
        while(pivot>arr[++i]);

        while(pivot<arr[--j]);

        if( i <= j)
            std::swap(arr[i],arr[j]);
        else
            break;
    }
    if(j > left)
        quick_sort(arr, left, j);
    if(i < right)
        quick_sort(arr, i, right);
}

int main() {
    int *arr, n;

    srand(time(NULL));
    n = 1000000;
    arr = new int[n];
    tmp = new int[n];

    for(int i = 0;i < n; i++){
        arr[i] = (std::rand()%(n-1) + 1);
    }

//   for(int i = 0; i < n; i++){
//       tab[i] = (std::rand()%(n-1) + 1);
//   }

    auto begin = std::chrono::steady_clock::now();
    //merge_sort(arr, 0, n-1);
    //insertion_sort(n , arr);
    //heapSort(arr, n);
    quick_sort(arr, 0 , n-1);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "Zmierznony czas algorytmu: " << elapsed.count() << "nanoseconds." << std::endl;

//    for(int i =0;i<n;i++){
//        std::cout << arr[i] <<"  ";
//    }

    return 0;
}
