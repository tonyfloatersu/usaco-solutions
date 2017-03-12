/*
ID: suhangt1
LANG: C
PROG: subset
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *fin = fopen("subset.in", "r");
	FILE *fout = fopen("subset.out", "w");
	int setsize; fscanf(fin, "%d", &setsize);
	long long storage[45][2000];
	for (int i = 0; i < 40; i++)
		for (int j = 0; j < 2000; j++)
			storage[i][j] = 0;
	for (int i = 0; i < 40; i++)
		storage[i][0] = 1, storage[i][1] = 1;
	if (setsize % 4 != 0 && setsize % 4 != 3) {
		fprintf(fout, "%d\n", 0);
		exit(0);
	} else {
		int max = (setsize + 1) * setsize / 4;
		for (int i = 2; i <= setsize; i++)
			for (int j = 1; j <= max; j++)
				storage[i][j] = storage[i - 1][j] + storage[i - 1][j - i];
	}
	fprintf(fout, "%lld\n", storage[setsize][setsize * (setsize + 1) / 4] / 2);
	exit(0);
}
