/*
ID: suhangt1
LANG: C
PROG: friday
 */

#include <stdio.h>
#include <stdlib.h>

int month_length(int year, int month);

int main() {
	FILE *fin = fopen("friday.in", "r");
	FILE *fout = fopen("friday.out", "w");
	int years;
	fscanf(fin, "%d", &years);
	int counter[7];
	for (int i = 0; i < 7; i++)
		counter[i] = 0;
	int current_year = 1900;
	int current_weekday = 1;
	for (int i = 0; i < years; i++) {
		for (int j = 1; j <= 12; j++) {
			counter[(current_weekday + 12) % 7]++;
			current_weekday += month_length(current_year, j);
			current_weekday %= 7;
		}
		current_year++;
	}
	fprintf(fout, "%d ", counter[6]);
	for (int i = 0; i < 5; i++)
		fprintf(fout, "%d ", counter[i]);
	fprintf(fout, "%d\n", counter[5]);
	exit(0);
}

int month_length(int year, int month) {
	int origin_length[12] =
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		origin_length[1] += 1;
	return origin_length[month - 1];
}
