/*
ID: suhangt1
LANG: C
PROG: skidesign
*/

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) < (b)) ? (a) : (b)

int main() {
	FILE *fin = fopen("skidesign.in", "r");
	FILE *fout = fopen("skidesign.out", "w");
	int hills; fscanf(fin, "%d", &hills);
	int mountain[1005];
	int max = 0, min = 10000;
	for (int i = 0; i < hills; i++) {
		fscanf(fin, "%d", &mountain[i]);
		if (mountain[i] > max)
			max = mountain[i];
		if (mountain[i] < min)
			min = mountain[i];
	}
	int cost = 1000000000;
	for (int i = min; i <= max - 17; i++) {
		int temp_cost = 0;
		for (int j = 0; j < hills; j++) {
			if (mountain[j] <= i)
				temp_cost += (i - mountain[j]) * (i - mountain[j]);
			else if (mountain[j] >= i + 17)
				temp_cost += (mountain[j] - i - 17) * (mountain[j] - i - 17);
		}
		cost = min(temp_cost, cost);
	}
	fprintf(fout, "%d\n", cost);
	exit(0);
}
