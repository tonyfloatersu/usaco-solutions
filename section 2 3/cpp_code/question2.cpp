/*
  ID: suhangt1
  PROG: nocows
  LANG: C++11
*/

#include <iostream>

#define MOD 9901

using namespace std;

int main() {
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
	int node, height; cin >> node >> height;
	int table[105][205];
	for (int i = 0; i < 105; i++)
		for (int j = 0; j < 205; j++)
			table[i][j] = 0;
    table[1][1] = 1;
	for (int i = 1; i <= height; i++)
		for (int j = 3; j <= node; j += 2) {
			int temp = 0;
			for (int p = 1; p <= i - 2; p++)
				for (int k = 1; k <= j - 2; k += 2)
					temp = (temp + table[p][j - k - 1] * table[i - 1][k]
                            + table[p][k] * table[i - 1][j - k - 1]) % MOD;
			for (int k = 1; k <= j - 2; k += 2)
				temp = (temp + table[i - 1][k] * table[i - 1][j - k - 1]) % MOD;
			table[i][j] = temp;
		}
    cout << table[height][node] << endl;
	return 0;
}
