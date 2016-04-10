#include <vector>

using namespace std;

// https://codility.com/programmers/task/missing_integer/
int solution(vector<int> &A) {
	int min = 0;	// Positive minimal
	for (int i = 0; i < A.size(); i++) {
		if (A[i] > 0 && (min == 0 || A[i] < min)) {
			min = A[i];
		}
	}
	if (min == 0 || min > 1) {
		return 1;
	}

	vector<int> possibleMissing(A.size(), 0);
	for (int i = 0; i < A.size(); i++) {
		int minOffset = A[i] - min - 1;
		if (minOffset >= 0 && minOffset < A.size()) {
			possibleMissing[minOffset]++;
		}
	}

	for (int i = 0; i < A.size(); i++) {
		if (possibleMissing[i] == 0) {
			return min + i + 1;
		}
	}
	return 0; 	// Will never run
}

int main() {

}
