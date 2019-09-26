#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n = 10; int j;
	int arr[10] = { 9,5,6,3,0,4,7,8,2,1 };

	for (int i = 1; i < n; i++) {
		int tmp = arr[i];


		for (j = i - 1; j >= 0; j--) {

			if (arr[j] > tmp)

				arr[j+1] = arr[j];

			else 
				break;
		}

		arr[j + 1] = tmp;
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	return 0;
}
