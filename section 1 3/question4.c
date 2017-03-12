/*
ID: suhangt1
LANG: C
PROG: combo
 */

#include <stdio.h>
#include <stdlib.h>

int is_inscope(int *test, int lock[][105], int scope);

int main() {
	FILE *fin = fopen("combo.in", "r");
	FILE *fout = fopen("combo.out", "w");
	int scope; fscanf(fin, "%d", &scope);
	int lock[3][105];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 105; j++)
			lock[i][j] = 0;
	for (int i = 0; i < 6; i++) {
		int temp; fscanf(fin, "%d", &temp);
		// first the farmer then the master
		lock[i % 3][temp] += (i / 3 + 1);
	}
	int testcount = 0;
	for (int i = 1; i <= scope; i++) {
		for (int j = 1; j <= scope; j++) {
			for (int k = 1; k <= scope; k++) {
				int test[3] = {i, j, k};
				if (is_inscope(test, lock, scope)) {
					testcount++;
				}
			}
		}
	}
    fprintf(fout, "%d\n", testcount);
	exit(0);
}

int is_inscope(int *test, int lock[][105], int scope) {
	int condition_jdg[6];
	for (int i = 0; i < 6; i++)
		condition_jdg[i] = 0;
	for (int i = -2; i <= 2; i++) {
		int tester[3];
		for (int j = 0; j < 3; j++)
			tester[j] = ((test[j] + i + scope) % scope == 0) ?
                        scope: (test[j] + i + scope) % scope;
		if (lock[0][tester[0]] == 1)
			condition_jdg[0] = 1;
		else if (lock[0][tester[0]] == 2)
			condition_jdg[3] = 2;
        else if (lock[0][tester[0]] == 3)
            condition_jdg[0] = 1, condition_jdg[3] = 2;
		if (lock[1][tester[1]] == 1)
			condition_jdg[1] = 1;
		else if (lock[1][tester[1]] == 2)
			condition_jdg[4] = 2;
        else if (lock[1][tester[1]] == 3)
            condition_jdg[1] = 1, condition_jdg[4] = 2;
		if (lock[2][tester[2]] == 1)
			condition_jdg[2] = 1;
		else if (lock[2][tester[2]] == 2)
			condition_jdg[5] = 2;
        else if (lock[2][tester[2]] == 3)
            condition_jdg[2] = 1, condition_jdg[5] = 2;
	}
	if (condition_jdg[0] == 1 && condition_jdg[1] == 1 && condition_jdg[2] == 1)
		return 1;
	else if (condition_jdg[3] == 2 && condition_jdg[4] == 2 && condition_jdg[5] == 2)
		return 1;
	else
		return 0;
}
