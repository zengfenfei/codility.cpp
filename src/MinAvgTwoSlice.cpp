#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

// https://codility.com/programmers/task/min_avg_two_slice/
// The minimal average must be 2 or 3 elements
int solution(vector<int> &A) {
	int n = A.size();
	int minI = 0;
	double minAvg = (A[0] + A[1]) / 2.0;
	for (int i = 0; i < n - 2; i++) {
		double avg = (A[i] + A[i + 1]) / 2.0;
		if (avg < minAvg) {
			minAvg = avg;
			minI = i;
		}
		avg = (A[i] + A[i + 1] + A[i + 2]) / 3.0;
		if (avg < minAvg) {
			minAvg = avg;
			minI = i;
		}
	}
	if (n > 2) {	// Check the last 2 elements
		double avg = (A[n - 2] + A[n - 1]) / 2.0;
		if (avg < minAvg) {
			minAvg = avg;
			minI = n - 2;
		}
	}
	return minI;
}

int main() {
	vector<int> A(7);
	A[0] = 4;
	A[1] = 2;
	A[2] = 2;
	A[3] = 5;
	A[4] = 1;
	A[5] = 5;
	A[6] = 8;

	cout << solution(A) << '\n';	// 1
}
