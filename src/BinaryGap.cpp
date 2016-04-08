#include <iostream>

using namespace std;

// https://codility.com/programmers/task/binary_gap/
int solution(int N) {
	int len = sizeof(N) * 8;
	int max0s = 0, cur0s = -1;
	for (int i = 0; i < len; ++i) {
		int bit = N & (1 << i);
		if (bit > 0) {	// bit is 1
			if (cur0s > max0s) {
				max0s = cur0s;
			}
			cur0s = 0;
		} else if (cur0s > -1) {
			cur0s++;
		}
	}
	return max0s;
}

int main() {
	cout << solution(1041) << "\n"; // 5
	cout << solution(20) << "\n";	// 1
}
