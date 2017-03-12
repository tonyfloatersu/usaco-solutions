/*
ID: suhangt1
PROG: zerosum
LANG: C++11
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

void dfs(int length, int sum, int buffer, int step, string answer) {
	if (step == length) {
		if (sum + buffer == 0)
			cout << answer << endl;
		return;
	}
	if (buffer > 0)
		dfs(length, sum, buffer * 10 + step + 1, step + 1, answer + ' ' + char(step + 1 + '0'));
	else
		dfs(length, sum, buffer * 10 - step - 1, step + 1, answer + ' ' + char(step + 1 + '0'));
	dfs(length, sum + buffer, step + 1, step + 1, answer + '+' + char(step + 1 + '0'));
	dfs(length, sum + buffer, -1 * step - 1, step + 1, answer + '-' + char(step + 1 + '0'));
}

int main() {
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
	int val; cin >> val;
	dfs(val, 0, 1, 1, (string)"1");
	return 0;
}
