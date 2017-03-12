/*
ID: suhangt1
LANG: C
PROG: pprime
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)

int is_prime(int num);
int length(int num);
int pnum_generate(int num);
int create_half(int num, int place);

int main() {
	FILE *fin = fopen("pprime.in", "r");
	FILE *fout = fopen("pprime.out", "w");
	int lbd, hbd; fscanf(fin, "%d %d", &lbd, &hbd);
	// from the lbd to the greatest aba under hbd.
	for (int i = create_half(lbd, 1); i <= create_half(hbd, 2); i++) {
		if (pnum_generate(i) >= lbd && pnum_generate(i) <= hbd) {
			if (i == 5 || i == 7) fprintf(fout, "%d\n", i);
			else if (i == 9 && lbd <= 11 && hbd >= 11) fprintf(fout, "%d\n", 11);
			else if (is_prime(pnum_generate(i))) fprintf(fout, "%d\n", pnum_generate(i));
		} else if (pnum_generate(i) < lbd)
			continue;
		else if (pnum_generate(i) > hbd)
			break;
	}
	exit(0);
}

int is_prime(int num) {
	for (int i = 2; i <= (int)(sqrt(num * 1.0)); i++)
		if (num % i == 0)
			return 0;
	return 1;
}

int length(int num) {
	int len = 0;
	while (num > 0)
		num /= 10, len++;
	return len;
}

int pnum_generate(int num) {
	int sum = num;
	for (int _sum = sum / 10; _sum > 0; _sum /= 10)
		sum = sum * 10 + _sum % 10;
	return sum;
}

int create_half(int num, int place) {
	int times = length(num) / 2 - (length(num) % 2 == 0 && place == 2);
	int result = num;
	for (int i = 0; i < times; i++)
		result /= 10;
	return result;
}
