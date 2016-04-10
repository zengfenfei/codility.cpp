#include <vector>
#include <iostream>

// https://codility.com/programmers/task/count_div/
int solution(int A, int B, int K) {
	int start = A;// The minimal value equal or greater than A that is divisible by K
	int r = A % K;
	if (r > 0) {
		start += K - r;
	}

	int len = B - start;
	if (len < 0) {
		return 0;
	}
	return len / K + 1;
}

int main() {
	std::cout << solution(6, 11, 2) << '\n';	// 3
}
