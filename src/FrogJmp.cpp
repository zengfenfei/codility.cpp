#include <iostream>

//https://codility.com/programmers/task/frog_jmp/
int solution(int X, int Y, int D) {
	int dist = Y - X;
	int steps = dist / D;
	if (dist % D > 0) {
		steps++;
	}

	return steps;
}

int main() {
	std::cout << solution(10, 85, 30) << '\n';	//3
}
