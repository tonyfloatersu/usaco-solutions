/*
ID: suhangt1
LANG: C
PROG: numtri
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)

int main() {
	FILE *fin = fopen("numtri.in", "r");
	FILE *fout = fopen("numtri.out", "w");
	int lines; fscanf(fin, "%d", &lines);
	int storage[1000]; memset(storage, 0, 1000 * sizeof(int));
	int weight[1000]; memset(weight, 0, 1000 * sizeof(int));
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j <= i; j++)
			fscanf(fin, "%d", &storage[j]);
		/*
		  . . . . weight    0 -> i - 1
		  |\|\|\|\
		  . . . . . input   0 -> i
		  . . . . . weight

		  . weight
		  |\
		  . . input
		  . . weight

		  . input
		  . weight
		 */
		if (i == 0)	weight[0] = storage[0];
		if (i != 0) weight[i] = storage[i] + weight[i - 1];
		else weight[1] = storage[0];
		for (int j = 1; j < i; j++)
			storage[j] += max(weight[j - 1], weight[j]);
		storage[0] += weight[0];
		for (int j = 0; j < i; j++)
			weight[j] = storage[j];
	}
	int max_num = 0;
	for (int i = 0; i < lines; i++)
		max_num = max(max_num, weight[i]);
	fprintf(fout, "%d\n", max_num);
	exit(0);
}
