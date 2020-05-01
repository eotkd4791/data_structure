#include <iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
    int i = r;

    int pivot = arr[l];

    for (int j = r; j > l; j--)

        if (arr[j] >= pivot) swap(arr[i--], arr[j]);

    swap(arr[i], arr[l]);
    
    return i;
}

void quickSort(int arr[], int l, int r) 
{
    if (l >= r) return;

    int p = partition(arr, l, r);

    quickSort(arr, l, p - 1);
    
    quickSort(arr, p + 1, r);
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0);

    int arr[10] = {4, 3, 5, 1, 2, 6, 9, 10, 8, 7};

    for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
    
    cout << '\n';

    quickSort(arr, 0, 9);

    for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
    
    cout << '\n';
    
    return 0;
}
