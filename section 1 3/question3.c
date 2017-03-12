/*
ID: suhangt1
LANG: C
PROG: crypt1
 */

#include <stdio.h>
#include <stdlib.h>

int validity(int data, int *arr);

int total_check(int data1, int data2, int *arr);

int main() {
	FILE *fin = fopen("crypt1.in", "r");
	FILE *fout = fopen("crypt1.out", "w");
	int use_num, num_arr[10];
	for (int i = 0; i < 10; i++)
		num_arr[i] = 0;
	fscanf(fin, "%d", &use_num);
	for (int i = 0; i < use_num; i++) {
		int temp; fscanf(fin, "%d", &temp);
		num_arr[temp] = 1;
	}
	int times = 0;
	for (int i = 111; i < 1000; i++) {
		for (int j = 11; j < 100; j++) {
			if (total_check(i, j, num_arr)) {
				times++;
			}}}
	fprintf(fout, "%d\n", times);
	exit(0);
}

int validity(int data, int *arr) {
	if (data == 0)
		return 0;
	else {
		while (data) {
			if (arr[data % 10] == 0)
				return 0;
			else
				data /= 10;
		}
	}
	return 1;
}

int total_check(int data1, int data2, int *arr) {
	int first = data2 / 10, second = data2 % 10;
	if (validity(data1, arr) && validity(data2, arr)
		&& data1 * first < 1000 && data1 * second < 1000
		&& validity(data1 * first, arr) && validity(data1 * second, arr)
		&& validity(data1 * data2, arr))
		return 1;
	return 0;
}
