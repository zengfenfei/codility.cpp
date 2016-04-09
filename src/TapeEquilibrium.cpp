#include <iostream>
#include <vector>
#include <stdlib.h>
#include <limits.h>

using namespace std;

//https://codility.com/programmers/task/tape_equilibrium/
//N is an integer within the range [2..100,000];
//each element of array A is an integer within the range [−1,000..1,000].
int solution(vector<int> &A) {
	int n = A.size();
	vector<int> leftSums(n), rightSums(n);
	leftSums[0] = A[0];
	for (int i = 1; i < n; i++) {
		leftSums[i] = leftSums[i - 1] + A[i];
	}

	rightSums[n - 1] = A[n - 1];
	int minDiff = abs(leftSums[n - 2] - rightSums[n - 1]);
	for (int i = n - 2; i > 0; i--) {
		rightSums[i] = rightSums[i + 1] + A[i];
		int diff = abs(leftSums[i - 1] - rightSums[i]);
		if (diff < minDiff) {
			minDiff = diff;
		}
	}
	return minDiff;
}

int main() {

}

