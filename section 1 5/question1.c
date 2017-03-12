/*
ID: suhangt1
LANG: C
PROG: numtri
 */

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)

void dfs(int map[][1000], int weight[][1000], int lines, int depth, int ltrplc, int direction);

int main() {
	FILE *fin = fopen("numtri.in", "r");
	FILE *fout = fopen("numtri.out", "w");
	int lines; fscanf(fin, "%d", &lines);
	int storage[1000][1000];
	for (int i = 0; i < lines; i++)
		for (int j = 0; j <= i; j++)
			fscanf(fin, "%d", &storage[i][j]);
	// dfs search.
	int weight[1000][1000];
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			weight[i][j] = 0;
	weight[0][0] = storage[0][0];
	dfs(storage, weight, lines, 0, 0, 1);
	dfs(storage, weight, lines, 0, 0, 0);
	int max_num = weight[lines - 1][0];
	for (int i = 0; i < lines - 1; i++)
		max_num = max(max_num, weight[lines - 1][i + 1]);
	fprintf(fout, "%d\n", max_num);
	exit(0);
}

void dfs(int map[][1000], int weight[][1000], int lines, int depth, int ltrplc, int direction) {
	if (depth == lines) return;
	weight[depth + 1][ltrplc + direction] =
		max(map[depth + 1][ltrplc + direction] + weight[depth][ltrplc],
			weight[depth + 1][ltrplc + direction]);
	dfs(map, weight, lines, depth + 1, ltrplc + direction, direction);
	dfs(map, weight, lines, depth + 1, ltrplc + direction, !direction);
}
