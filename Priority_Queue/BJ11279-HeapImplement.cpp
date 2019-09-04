#include <iostream>
#define INF 1000000
using namespace std;

int N;
int heap[INF];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x = 0; int idx = 1; int inow = 1;

	cin >> N;
	while (N--) {
		cin >> x;
		
		if (x != 0) {
			if (heap[1] == 0) {
				heap[1] = x;
				inow = 1;
			}

			else {
				if (heap[idx * 2] == 0) {
					heap[idx * 2] = x;
					
					if (heap[idx * 2] >= heap[idx]) {
						swap(heap[idx * 2], heap[idx]);
						int tmp = idx;
						while (1) {
							if (heap[tmp / 2] >= heap[tmp])
								break;
							if (tmp / 2 == 0)
								break;
							swap(heap[tmp / 2], heap[tmp]);
							tmp /= 2;
						}
					}
					inow = idx * 2;
				}
				else {
					heap[idx * 2 + 1] = x;

					if (heap[idx * 2 + 1] >= heap[idx]) {
						swap(heap[idx * 2 + 1], heap[idx]);
						int tmp = idx;
						while (1) {
							if (heap[tmp / 2] >= heap[tmp])
								break;
							if (tmp / 2 == 0)
								break;
							swap(heap[tmp / 2], heap[tmp]);
							tmp /= 2;
						}
					}
					inow = idx * 2 + 1;
					idx++;
				}
			}
		}
		else {
			cout << heap[1] << '\n';
			if (heap[1] == 0) {
				idx = 1;
				inow = 1;
				continue;
			}
	
			heap[1] = heap[inow];
			heap[inow] = 0;
			idx = inow / 2;

			int tmp = 1;
			if (heap[2] > heap[1] || heap[1] < heap[3]) {
				while (1) {
					if (heap[tmp] >= heap[tmp * 2] && heap[tmp] >= heap[tmp * 2 + 1])
						break;
					if (heap[tmp * 2] == 0 && heap[tmp * 2 + 1] == 0)
						break;

					if (heap[tmp * 2] >= heap[tmp * 2 + 1]) {
						swap(heap[tmp], heap[tmp * 2]);
						tmp *= 2;
					}
					else if (heap[tmp * 2] <= heap[tmp * 2 + 1]) {
						swap(heap[tmp], heap[tmp * 2 + 1]);
						tmp = tmp * 2 + 1;
					}
				}
			}
		}
	}
	return 0;
}