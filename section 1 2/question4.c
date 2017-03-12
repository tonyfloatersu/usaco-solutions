/*
ID: suhangt1
LANG: C
PROG: palsquare
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void base_trans(int target, int base, char *dest);

int is_dual(char *arr);

int main() {
	FILE *fin = fopen("palsquare.in", "r");
	FILE *fout = fopen("palsquare.out", "w");
	int base; fscanf(fin, "%d", &base);
	int square[300];
	for (int i = 0; i < 300; i++)
		square[i] = (i + 1) * (i + 1);
	char transform[300][30];
	for (int i = 0; i < 300; i++)
		for (int j = 0; j < 20; j++)
			transform[i][j] = '\0';
	for (int i = 0; i < 300; i++)
		base_trans(square[i], base, transform[i]);
	char const_area[30];
	for (int i = 0; i < 30; i++)
		const_area[i] = '\0';
	for (int i = 0; i < 300; i++) {
		if (is_dual(transform[i])) {
			base_trans(i + 1, base, const_area);
			fprintf(fout, "%s %s\n", const_area, transform[i]);
		}
	}
	exit(0);
}

void base_trans(int target, int base, char *dest) {
	int place = 0;
	while (target != 0) {
		int current = target % base;
		target /= base;
		if (current < 10)
			dest[place] = '0' + current;
		else if (current >= 10)
			dest[place] = 'A' + current - 10;
		place++;
	}
	for (int i = 0; i <= (int)(place / 2) - 1; i++) {
		char temp = dest[i];
		dest[i] = dest[place - 1 - i];
		dest[place - 1 - i] = temp;
	}
}

int is_dual(char *arr) {
	int len = 0;
	while (arr[len] != '\0')
		len += 1;
	int i = 0, result = 1;
	while (1) {
		if (arr[i] != arr[len - i - 1])
			result = 0;
		if (i != len - 1 - i && i + 1 != len - 1 - i)
			i += 1;
		else
			break;
	}
	return result;
}
