/*
ID: suhangt1
LANG: C
PROG: subset
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dfs(int sum, int upper);

int main() {
	FILE *fin = fopen("subset.in", "r");
	FILE *fout = fopen("subset.out", "w");
	int setsize; fscanf(fin, "%d", &setsize);
	if (setsize % 4 != 0 && setsize % 4 != 3)
		fprintf(fout, "%d\n", 0);
	else {
		int possibility = dfs((setsize + 1) * setsize / 4, setsize);
		if ((setsize + 1) * setsize / 4 == setsize)
			possibility /= 2;
		printf("%d\n", possibility);
	}
	exit(0);
}

int dfs(int sum, int upper) {
	if (sum > (1 + upper) * upper / 2) return 0;
	int times = 0;
	if (upper <= 0)	return 0;
	for (int i = upper - 1; i >= 0; i--) {
		if (sum > upper) {
			times += dfs(sum - upper, i);
			if (sum - upper <= i)
				break;
		}
		else if (sum < upper) {
			times += dfs(sum, sum);
			break;
		} else {
			times++;
			times += dfs(sum, upper - 1);
			break;
		}
	}
	return times;
}
