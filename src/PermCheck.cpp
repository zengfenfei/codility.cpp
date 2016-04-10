#include <vector>
#include <iostream>

using namespace std;

// https://codility.com/programmers/task/perm_check/
int solution(vector<int> &A) {
	unsigned int n = A.size();
	vector<bool> occurs(n, false);	// occurrence of 1 ~ n
	for (unsigned int i = 0; i < n; i++) {
		if (A[i] < 1 || A[i] > n) {
			return 0;
		}
		if (occurs[A[i] - 1]) {
			return 0;
		} else {
			occurs[A[i] - 1] = true;
		}
	}
	return 1;
}

int main() {
	vector<int> A(4);
	A[0] = 4;
	A[1] = 1;
	A[2] = 3;
	A[3] = 2;
	cout << solution(A) << '\n';	// 1
}
