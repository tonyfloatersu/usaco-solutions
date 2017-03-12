/*
ID: suhangt1
LANG: C
PROG: frac1
*/

#include <stdio.h>
#include <stdlib.h>

void printinorder(int m, int n, int mm, int nn, FILE *fout, int lbd);

int main() {
	FILE *fin = fopen("frac1.in", "r");
	FILE *fout = fopen("frac1.out", "w");
	int lbd; fscanf(fin, "%d", &lbd);
	fprintf(fout, "0/1\n");
	printinorder(0, 1, 1, 1, fout, lbd + 1);
	fprintf(fout, "1/1\n");
	exit(0);
}

// http://blog.csdn.net/sio__five/article/details/19764105
// Stern–Brocot tree

void printinorder(int m, int n, int mm, int nn, FILE *fout, int lbd) {
	if (n + nn < lbd) {
		printinorder(m, n, mm + m, nn + n, fout, lbd);
		fprintf(fout, "%d/%d\n", mm + m, nn + n);
		printinorder(m + mm, nn + n, mm, nn, fout, lbd);
	}
}
