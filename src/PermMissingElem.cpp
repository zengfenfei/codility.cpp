#include <vector>
#include <iostream>

using namespace std;

// https://codility.com/programmers/task/perm_missing_elem/
int solution(vector<int> &A) {
	int fullSum = 0;	// sum: 1 + 2 + ... n
	int sum = 0;	// sum of input Array A
	int i;
	for (i = 0; i < A.size(); i++) {
		sum += A[i];
		fullSum += i + 1;
	}
	fullSum += i + 1;
	return fullSum - sum;
}

int main() {
	vector<int> A(4);
	A[0] = 2;
	A[1] = 3;
	A[2] = 1;
	A[3] = 5;
	cout << solution(A) << '\n';	// 3
	return 0;
}
