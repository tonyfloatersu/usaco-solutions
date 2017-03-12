/*
ID: suhangt1
PROG: money
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
	int coin_variety, amount; cin >> coin_variety >> amount;
	long long money_table[10005];
	for (int i = 0; i < 10005; i++) money_table[i] = 0;
	money_table[0] = 1;
	for (int i = 0; i < coin_variety; i++) {
		int temp; cin >> temp;
		for (int j = temp; j <= amount; j++)
			money_table[j] += money_table[j - temp];
	}
	cout << money_table[amount] << endl;
    return 0;
}
