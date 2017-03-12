/*
ID: suhangt1
LANG: C
PROG: sort3
 */

#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b)) ? (a) : (b)

int main() {
	FILE *fin = fopen("sort3.in", "r");
	FILE *fout = fopen("sort3.out", "w");
	int size; fscanf(fin, "%d", &size);
	int store[1005];
	int count1 = 0, count2 = 0, count3 = 0;
	for (int i = 0; i < size; i++) {
		fscanf(fin, "%d", &store[i]);
		count1 += (store[i] == 1);
		count2 += (store[i] == 2);
		count3 += (store[i] == 3);
	}
	for (int i = 0; i < size; i++)
		printf("%d ", store[i]);
	printf("\n");
	int well_order[1005];
	for (int i = 0; i < size; i++)
		well_order[i] = 1 * (i >= 0 && i < count1)
			+ 2 * (i >= count1 && i < count1 + count2)
			+ 3 * (i >= count1 + count2 && i < size);
	for (int i = 0; i < size; i++)
		printf("%d ", well_order[i]);
	printf("\n");
	int step_count = 0;
	// then I can get it work like this
	int error_plc[10];
	for (int i = 0; i < size; i++)
		if (well_order[i] != store[i])
			error_plc[store[i] - 1
					  + 0 * (i >= 0 && i < count1)
					  + 3 * (i >= count1 && i < count1 + count2)
					  + 6 * (i >= count1 + count2 && i < size)]++;
	for (int i = 0; i < 9; i++)
		printf("%d ", error_plc[i]);
	int temp = min(error_plc[1], error_plc[3]);
	step_count += temp;
	error_plc[1] -= temp, error_plc[3] -= temp;
	printf("%d\n", temp);
	temp = min(error_plc[5], error_plc[7]);
	step_count += temp;
	error_plc[5] -= temp, error_plc[7] -= temp;
	printf("%d\n", temp);
	temp = min(error_plc[2], error_plc[6]);
	step_count += temp;
	error_plc[2] -= temp, error_plc[6] -= temp;
	printf("%d\n", temp);
	for (int i = 0; i < 9; i++)
		if (error_plc[i] != 0) {
			step_count += error_plc[i] * 2;
			break;
		}
	fprintf(fout, "%d\n", step_count);
	exit(0);
}
