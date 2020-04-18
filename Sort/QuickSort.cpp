#include <iostream>
#define MAX 10
using namespace std;

int Partition(int arr[], int start, int end)
{
    int idx = start;

    int pivot = arr[end];

    for(int i = start; i < end; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[i], arr[idx]);

            idx++;
        }
    }
    swap(arr[idx], arr[end]);

    return idx;
}

void quickSort(int arr[], int start, int end)
{
    if(start >= end) return;

    int idx = Partition(arr, start, end);

    quickSort(arr, start, idx - 1);

    quickSort(arr, idx + 1, end);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int arr[] = {7, 4, 5, 1, 6, 2, 3, 9, 0, 8};

    cout << '\n' << "before" << ' ' << "sorting" << '\n';

    for(int i = 0; i < MAX; i++) cout << arr[i] << ' ';

    quickSort(arr, 0, MAX - 1);

    cout << '\n' << "after" << ' ' << "sorting" << '\n';

    for(int i = 0; i < MAX; i++) cout << arr[i] << ' ';

    return 0;
}
