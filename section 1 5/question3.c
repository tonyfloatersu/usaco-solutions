/*
ID: suhangt1
LANG: C
PROG: sprime
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_prime(int num);
void dfs(int number, int depth, FILE *fout);

int main() {
	FILE *fin = fopen("sprime.in", "r");
	FILE *fout = fopen("sprime.out", "w");
	int len; fscanf(fin, "%d", &len);
	/*
	  consider the problem:
	  first element must be 2 3 5 7 prime
	  then later must be 1 3 7 9
	  so we can get it kind of easily.
	 */
	dfs(2, len - 1, fout);
	dfs(3, len - 1, fout);
	dfs(5, len - 1, fout);
	dfs(7, len - 1, fout);
	exit(0);
}

int is_prime(int num) {
	for (int i = 2; i <= (int)(sqrt(num * 1.0)); i++)
		if (num % i == 0)
			return 0;
	return 1;
}

void dfs(int number, int depth, FILE *fout) {
	if (!is_prime(number)) return;
	if (depth == 0) {
		fprintf(fout, "%d\n", number);
		return;
	}
	dfs(number * 10 + 1, depth - 1, fout);
	dfs(number * 10 + 3, depth - 1, fout);
	dfs(number * 10 + 7, depth - 1, fout);
	dfs(number * 10 + 9, depth - 1, fout);
}
