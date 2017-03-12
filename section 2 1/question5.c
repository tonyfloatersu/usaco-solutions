/*
ID: suhangt1
LANG: C
PROG: hamming
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) > (b)) ? (a) : (b)

int hamming_dist_test(int val_a, int val_b, int bit_length, int least_length);

int main() {
	FILE *fin = fopen("hamming.in", "r");
	FILE *fout = fopen("hamming.out", "w");
	int codewords_num, bit_length, least_distance;
	fscanf(fin, "%d %d %d", &codewords_num, &bit_length, &least_distance);
	// basic data retrieve
	int bit_saperate[10]; bit_saperate[0] = 1;
	for (int i = 1; i < 8; i++) bit_saperate[i] = bit_saperate[i - 1] * 2;
	int storage[300]; for (int i = 0; i < 300; i++) storage[i] = 0;
	int total = 1, current = 1;
	while (total <= codewords_num - 1) {
		int check = 0;
		for (int i = 0; i < total; i++) {
			if (!hamming_dist_test(storage[i], current, bit_length, least_distance))
				break;
			else
				check++;
			if (check >= total) {
				storage[total] = current;
				total++;
			}
		}
		current++;
	}
	for (int i = 0; i < total; i++) {
		fprintf(fout, "%d", storage[i]);
		fprintf(fout, (i % 10 == 9 || i == total - 1) ? "\n" : " ");
	}
	exit(0);
}

int hamming_dist_test(int val_a, int val_b, int bit_length, int least_length) {
	int counter = 0;
	for (int i = 0; i < bit_length; i++) {
		if (((val_a >> i) & 1) != ((val_b >> i) & 1))
			counter++;
		if (counter >= least_length)
			return 1;
	}
	return 0;
}
