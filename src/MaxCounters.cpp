#include <vector>
#include <iostream>

using namespace std;

// https://codility.com/programmers/task/max_counters/
vector<int> solution(int N, vector<int> &A) {
	vector<int> counters(N, 0);
	int max = 0;
	int lastMax = 0;
	for (int i = 0; i < A.size(); i++) {
		int op = A[i];
		if (op >= 1 && op <= N) {
			int count = counters[op - 1];
			if (count < lastMax) {
				count = lastMax;
			}
			count++;
			if (count > max) {
				max = count;
			}
			counters[op - 1] = count;
		} else if (op == N + 1) {
			lastMax = max;
		}
	}
	for (int i = 0; i < N; i++) {
		if (counters[i] < lastMax) {
			counters[i] = lastMax;
		}
	}
	return counters;
}

int main() {
	vector<int> A(7);
	A[0] = 3;
	A[1] = 4;
	A[2] = 4;
	A[3] = 6;
	A[4] = 1;
	A[5] = 4;
	A[6] = 4;
	vector<int> counters = solution(5, A);
	for (int i = 0; i < counters.size(); i++) {
		cout << counters[i] << ',';
	}
	cout << '\n';
}
