/*
  ID: suhangt1
  PROG: concom
  LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
	int triple_num; cin >> triple_num;
	int table[105][105];
	for (int i = 0; i < 105; i++)
		for (int j = 0; j < 105; j++)
			table[i][j] = 0;
	for (int i = 0; i < 105; i++)
		table[i][i] = 100;
	for (int i = 0; i < triple_num; i++) {
		int temp_comp_1, temp_comp_2, temp_control;
		cin >> temp_comp_1 >> temp_comp_2 >> temp_control;
		table[temp_comp_1][temp_comp_2] = temp_control;
	}
	bool control_count[105][105];
	for (int i = 0; i < 105; i++)
		for (int j = 0; j < 105; j++)
			control_count[i][j] = (table[i][j] >= 50) ? true : false;
	for (int i = 1; i <= 100; i++) {
		bool flag = true;
		while (flag) {
			flag = false;
			for (int j = 1; j <= 100; j++) {
				if (!control_count[i][j]) {
					int sum = 0;
					for (int k = 1; k <= 100; k++)
						if (control_count[i][k])
							sum += table[k][j];
					if (sum > 50) {
						control_count[i][j] = true;
						flag = true;
					}
				}
			}
		}
	}
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			if (control_count[i][j] && i != j)
				cout << i << " " << j << endl;
	return 0;
}
