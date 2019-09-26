
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n = 10; int MIN;
	int arr[10] = { 9,5,6,3,0,4,7,8,2,1 };

	for (int i = 0; i < n - 1; i++) {

		int MIN = i;


		for (int j = i + 1; j < n; j++) 

			if (arr[MIN] > arr[j])

				MIN = j;
		


		swap(arr[MIN], arr[i]);
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	return 0;
}