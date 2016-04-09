#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	int odd = A[0];
	for (int i = 1; i < A.size(); i++) {
		odd ^= A[i];
	}
	return odd;
}

int main() {
	int a[] = { 9, 3, 9, 3, 9, 7, 9 };
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	cout << solution(vec) << "\n";	//7
	return 0;
}
