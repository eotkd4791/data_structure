#include <iostream>
#define MAX 10
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int tmp[MAX] = {};

    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if(arr[i] < arr[j]) tmp[k++] = arr[i++];

        else tmp[k++] = arr[j++];
    }

    while(i <= mid) tmp[k++] = arr[i++];

    while(j <= high) tmp[k++] = arr[j++];

    k--;

    while(k >= 0)
    {
        arr[low + k] = tmp[k];

        k--;
    }
}



void mergeSort(int arr[], int low, int high)
{
    if(low >= high) return;

    else {
       int mid = (low + high) / 2;

       mergeSort(arr, low, mid);

       mergeSort(arr, mid + 1, high);

       merge(arr, low, mid, high);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int arr[] = {7, 4, 5, 1, 6, 2, 3, 9, 0, 8};

    cout << '\n' << "before" << ' ' << "sorting" << '\n';

    for(int i = 0; i < MAX; i++) cout << arr[i] << ' ';

    mergeSort(arr, 0, MAX - 1);

    cout << '\n' << "after" << ' ' << "sorting" << '\n';

    for(int i = 0; i < MAX; i++) cout << arr[i] << ' ';

    return 0;
}
