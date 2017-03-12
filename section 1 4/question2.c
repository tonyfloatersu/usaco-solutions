/*
ID: suhangt1
LANG: C
PROG: milk3
*/

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) < (b)) ? (a) : (b)

void dfs(int a, int b, int c, int rem[][30], int bottles[]);

int main() {
	FILE *fin = fopen("milk3.in", "r");
	FILE *fout = fopen("milk3.out", "w");
	int bottles[3];	fscanf(fin, "%d %d %d", &bottles[0], &bottles[1], &bottles[2]);
	int possibility[30][30];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			possibility[i][j] = 0;
	dfs(0, 0, bottles[2], possibility, bottles);
	for (int i = 0; i < bottles[2]; i++)
		if (possibility[0][i])
			fprintf(fout, "%d ", i);
	fprintf(fout, "%d\n", bottles[2]);
	exit(0);
}

void dfs(int a, int b, int c, int rem[][30], int bottles[]) {
	if (rem[a][c]) return;
	rem[a][c] = 1;
	// a -> b
	dfs(max(a + b - bottles[1], 0), min(bottles[1], a + b), c, rem, bottles);
	// b -> a
	dfs(min(a + b, bottles[0]), max(0, a + b - bottles[0]), c, rem, bottles);
	// a -> c
	dfs(max(0, a + c - bottles[2]), b, min(bottles[2], a + c), rem, bottles);
	// c -> a
	dfs(min(a + c, bottles[0]), b, max(0, a + c - bottles[0]), rem, bottles);
	// b -> c
	dfs(a, max(b + c - bottles[2], 0), min(b + c, bottles[2]), rem, bottles);
	// c -> b
	dfs(a, min(b + c, bottles[1]), max(b + c - bottles[1], 0), rem, bottles);
}
