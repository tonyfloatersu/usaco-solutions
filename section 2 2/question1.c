/*
ID: suhangt1
LANG: C
PROG: preface
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct rome {
	int val;
	char sym;
	int times_count;
} ROM;

int main() {
	FILE *fin = fopen("preface.in", "r");
	FILE *fout = fopen("preface.out", "w");
	int num; fscanf(fin, "%d", &num);
	ROM levels[10];
	for (int i = 0; i < 7; i++)
		levels[i].times_count = 0;
	levels[0].sym = 'I', levels[0].val = 1;
	levels[1].sym = 'V', levels[1].val = 5;
	levels[2].sym = 'X', levels[2].val = 10;
	levels[3].sym = 'L', levels[3].val = 50;
	levels[4].sym = 'C', levels[4].val = 100;
	levels[5].sym = 'D', levels[5].val = 500;
	levels[6].sym = 'M', levels[6].val = 1000;
	for (int i = 1; i <= num; i++) {
		int dig = i % 10, ten = (i % 100) / 10, hun = (i / 100) % 10, thou = i / 1000;
		levels[6].times_count += thou;
		if (hun < 4) levels[4].times_count += hun;
		else {
			if (hun > 4 && hun < 9)
				levels[4].times_count += (hun - 5), levels[5].times_count += 1;
			else if (hun == 4)
				levels[4].times_count += 1, levels[5].times_count += 1;
			else if (hun == 9)
				levels[6].times_count += 1, levels[4].times_count += 1;
		}
		if (ten < 4) levels[2].times_count += ten;
		else {
			if (ten > 4 && ten < 9)
				levels[2].times_count += (ten - 5), levels[3].times_count += 1;
			else if (ten == 4)
				levels[2].times_count += 1, levels[3].times_count += 1;
			else if (ten == 9)
				levels[2].times_count += 1, levels[4].times_count += 1;
		}
		if (dig < 4) levels[0].times_count += dig;
		else {
			if (dig > 4 && dig < 9)
				levels[0].times_count += (dig - 5), levels[1].times_count += 1;
			else if (dig == 4)
				levels[0].times_count += 1, levels[1].times_count += 1;
			else if (dig == 9)
				levels[2].times_count += 1, levels[0].times_count += 1;
		}
	}
	for (int i = 0; i < 7; i++)
		if (levels[i].times_count > 0)
			fprintf(fout, "%c %d\n", levels[i].sym, levels[i].times_count);
	exit(0);
}
