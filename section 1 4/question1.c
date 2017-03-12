/*
LANG: C
ID: suhangt1
PROG: ariprog
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct prog {
	int j;
	int i;
} PROG;

int main() {
	FILE *fin = fopen("ariprog.in", "r");
	FILE *fout = fopen("ariprog.out", "w");
	int length, upper_bound;
	fscanf(fin, "%d %d", &length, &upper_bound);
	char dual_square[150000];
	for (int i = 0; i < 150000; i++)
		dual_square[i] = 0;
	for (int p = 0; p <= upper_bound; p++)
		for (int q = 0; q <= upper_bound; q++)
			dual_square[p * p + q * q] = 1;
	int place_rem[70000], count_plc = 0;
	for (int i = 0; i < 70000; i++) { place_rem[i] = 0; }
	for (int i = 0; i <= 2 * upper_bound * upper_bound; i++)
		if (dual_square[i] == 1)
			place_rem[count_plc] = i, count_plc++;
	PROG storage[1000];
	for (int i = 0; i < 1000; storage[i].i =0, storage[i].j = 0, i++);
	// headache...
	int counter = 0;
	for (int i = 0; i < count_plc; i++) {
		int next = i + 1;
		while (next < count_plc) {
			int checker = 1;
			int step = place_rem[next] - place_rem[i];
			for (int k = 0; k < length; k++) {
				if (place_rem[i] + k * step > 2 * upper_bound * upper_bound
					|| dual_square[place_rem[i] + k * step] == 0) {
					checker = 0;
					break;
				}
			}
			if (checker)
				storage[counter].j = place_rem[i], storage[counter].i = step, counter++;
			next++;
		}
	}
	if (!counter)
		fprintf(fout, "NONE\n");
	else {
		for (int i = 0; i < counter; i++)
			for (int j = 0; j < counter - 1; j++) {
				if (storage[j].i > storage[j + 1].i) {
					PROG temp = storage[j];
					storage[j] = storage[j + 1];
					storage[j + 1] = temp;
				}
			}
		// then sort in small parts.
		for (int i = 0; i < counter; i++)
			fprintf(fout, "%d %d\n", storage[i].j, storage[i].i);}
	exit(0);
}
