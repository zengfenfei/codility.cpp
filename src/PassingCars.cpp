#include <vector>
#include <iostream>

using namespace std;

// https://codility.com/programmers/task/passing_cars/
int solution(vector<int> &A) {
	int carsToEast = 0;
	int pairs = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == 0) {
			carsToEast++;
		} else {
			pairs += carsToEast;
		}
		if (pairs > 1000000000) {
			return -1;
		}
	}
	return pairs;
}

int main() {
	vector<int> A(5);
	A[0] = 0;
	A[1] = 1;
	A[2] = 0;
	A[3] = 1;
	A[4] = 1;

	cout << solution(A) << '\n';	// 5
}
