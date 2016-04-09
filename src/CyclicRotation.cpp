#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
	int n = A.size();
	vector<int> rotated(n);
	if (n == 0) {
		return rotated;
	}
	K = K % n;
	//Move the first part to end
	for (int i = K; i < n; i++) {
		rotated[i] = A[i - K];
	}

	//Move the shifted part to the beginning
	for (int i = 0; i < K; i++) {
		rotated[i] = A[i + n - K];
	}
	return rotated;
}

void printVector(vector<int> out) {
	cout << "[";
	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << ",";
	}
	cout << "]";
}

int main() {
	int ints[] = { 3, 8, 9, 7, 6 };
	vector<int> a(ints, ints + sizeof(ints) / sizeof(int));
	vector<int> out = solution(a, 3);
	printVector(out);
	printVector(vector<int>());
	//9, 7, 6, 3, 8
}


