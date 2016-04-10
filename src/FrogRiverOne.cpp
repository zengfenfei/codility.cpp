#include <vector>
#include <iostream>

using namespace std;

//https://codility.com/programmers/task/frog_river_one/
int solution(int X, vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	vector<bool> hasLeaves(X, false);
	int validLeaves = 0;
	for (unsigned int i = 0; i < A.size(); i++) {
		bool has = hasLeaves[A[i] - 1];
		if (!has) {
			hasLeaves[A[i] - 1] = true;
			validLeaves++;
			if (validLeaves == X) {
				return i;
			}
		}
	}
	return -1;
}

int main() {
	vector<int> A(8);
	A[0] = 1;
	A[1] = 3;
	A[2] = 1;
	A[3] = 4;
	A[4] = 2;
	A[5] = 3;
	A[6] = 5;
	A[7] = 4;
	cout << solution(5, A) << '\n';	// 6
}
