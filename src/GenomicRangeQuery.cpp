#include <vector>
#include <map>
#include <iostream>

using namespace std;

// https://codility.com/programmers/task/genomic_range_query/
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
	// Calculate prefix counts
	int n = S.length();
	string types = "ACGT";
	int factors[4] = { 1, 2, 3, 4 }; // Ascending order and corresponds to order of types
	map<char, int> type2factorIdx;
	for (int i = 0; i < types.length(); i++) {
		type2factorIdx[types[i]] = i;
	}
	vector<vector<int> > prefixCounts(types.length() - 1,
			vector<int>(n + 1, 0));
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < prefixCounts.size(); j++) {
			prefixCounts[j][i] = prefixCounts[j][i - 1];
		}
		int facI = type2factorIdx[S[i - 1]];
		if (facI < prefixCounts.size()) {
			prefixCounts[facI][i]++;
		}
	}

	int m = P.size();
	vector<int> result(m);
	for (int i = 0; i < m; i++) {
		int f = P[i], t = Q[i] + 1;
		for (int j = 0; j < types.length(); j++) {
			if (j < prefixCounts.size()) {
				int count = prefixCounts[j][t] - prefixCounts[j][f];
				if (count > 0) {
					result[i] = factors[j];
					break;
				}
			} else {
				result[i] = factors[j];
			}
		}
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
	cout << '\n';
}
