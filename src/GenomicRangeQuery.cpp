#include <vector>
#include <iostream>

using namespace std;

// https://codility.com/programmers/task/genomic_range_query/
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
	// Calculate prefix counts
	int n = S.length();
	vector<int> prefixCountA(n + 1, 0);	//1
	vector<int> prefixCountC(n + 1, 0);	//2
	vector<int> prefixCountG(n + 1, 0);	//3
	for (int i = 1; i < n + 1; i++) {
		prefixCountA[i] = prefixCountA[i - 1];
		prefixCountC[i] = prefixCountC[i - 1];
		prefixCountG[i] = prefixCountG[i - 1];
		switch (S[i - 1]) {
		case 'A':
			prefixCountA[i]++;
			break;
		case 'C':
			prefixCountC[i]++;
			break;
		case 'G':
			prefixCountG[i]++;
			break;
		}
	}

	int m = P.size();
	vector<int> result(m);
	for (int i = 0; i < m; i++) {
		int f = P[i], t = Q[i] + 1;
		int count = prefixCountA[t] - prefixCountA[f];
		if (count > 0) {
			result[i] = 1;
			continue;
		}
		count = prefixCountC[t] - prefixCountC[f];
		if (count > 0) {
			result[i] = 2;
			continue;
		}
		count = prefixCountG[t] - prefixCountG[f];
		if (count > 0) {
			result[i] = 3;
			continue;
		}
		result[i] = 4;
	}
	return result;
}

int main() {
	string s = "CAGCCTA";
	vector<int> P(3), Q(3);
	P[0] = 2;
	Q[0] = 4;
	P[1] = 5;
	Q[1] = 5;
	P[2] = 0;
	Q[2] = 6;
	vector<int> res = solution(s, P, Q);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ',';
	}
}
