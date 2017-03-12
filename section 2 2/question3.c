/*
ID: suhangt1
PROG: runround
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

int validity(int num);

int main() {
	FILE *fin = fopen("runround.in", "r");
	FILE *fout = fopen("runround.out", "w");
	int lbd; fscanf(fin, "%d", &lbd);
	lbd += 1;
	int array[100];
	while (1) {
		if (!validity(lbd)) {lbd++; continue;}
		int digit = lbd, digit_count = 0, digit_frac = lbd;
		while (digit > 0)
			digit /= 10, digit_count++;
		for (int i = digit_count - 1; i >= 0; i--) {
			array[i] = digit_frac % 10;
			digit_frac /= 10;
		}
		int check_point = array[0];
		int place = 0;
		int touch[100];
		for (int i = 0; i < 100; i++) touch[i] = 0;
		for (int i = 0; i < digit_count; i++) {
			touch[place]++;
			place += array[place];
			place %= digit_count;
			int test = 1;
			for (int i = 0; i < digit_count; i++)
				if (touch[i] == 0)
					test = 0;
			touch[place]++;
			if (array[place] == check_point && test) {
				fprintf(fout, "%d\n", lbd);
				exit(0);
			}
		}
		lbd++;
	}
	exit(0);
}

int validity(int num) {
	int arr[10];
	for (int i = 0; i < 10; i++) arr[i] = 0;
	while (num > 0) {
		arr[num % 10]++;
		if (arr[num % 10] > 1) return 0;
		num /= 10;
	}
	if (arr[0] != 0)
		return 0;
	else
		return 1;
}
