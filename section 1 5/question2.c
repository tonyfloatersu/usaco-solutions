/*
ID: suhangt1
LANG: C
PROG: pprime
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LEN 10000005

int main() {
	FILE *fin = fopen("pprime.in", "r");
	FILE *fout = fopen("pprime.out", "w");
	int lbd, hbd; fscanf(fin, "%d %d", &lbd, &hbd);
	int _lbd = lbd, _hbd = hbd;
	int lbd_dig = 0, hbd_dig = 0;
	while (_lbd > 0)
		_lbd /= 10, lbd_dig++;
	while (_hbd > 0)
		_hbd /= 10, hbd_dig++;
	char prime_table[MAX_LEN]; memset(prime_table, 1, (MAX_LEN - 1) * sizeof(char));
	for (int i = 2; i <= (int)(sqrt(MAX_LEN * 1.0)); i++) {
		int count = 0;
		while (i * count < MAX_LEN) {
			prime_table[i * count] = 0;
			count++;
		}
	}
	prime_table[5] += 1; prime_table[7] += 1;
	for (int i = 1; i < 10000; i++) {
		int elem = i, _elem = i;
		while (_elem > 0) {
			elem = elem * 10 + _elem % 10;
			_elem /= 10;
		}
		prime_table[elem] += 1;
	}
	for (int i = 10; i < 10000; i++) {
		int elem = i, _elem = i / 10;
		while (_elem > 0) {
			elem = elem * 10 + _elem % 10;
			_elem /= 10;
		}
		prime_table[elem] += 1;
	}
	for (int i = lbd; i <= hbd; i++)
		if (prime_table[i] == 2)
			fprintf(fout, "%d\n", i);
	exit(0);
}
