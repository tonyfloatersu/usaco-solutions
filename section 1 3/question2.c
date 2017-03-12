/*
ID: suhangt1
LANG: C
PROG: barn1
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int lft;
	int rht;
} NODE;

int main() {
	FILE *fin = fopen("barn1.in", "r");
	FILE *fout = fopen("barn1.out", "w");
	int board_num_limit, stall_num, cow_num;
	fscanf(fin, "%d %d %d", &board_num_limit, &stall_num, &cow_num);
	int stalls[200];
	for (int i = 0; i < cow_num; i++)
		fscanf(fin, "%d", &stalls[i]);
	for (int i = 0; i < cow_num; i++) {
		for (int j = 0; j < cow_num - 1; j++) {
			if (stalls[j] > stalls[j + 1]) {
				int temp = stalls[j + 1];
				stalls[j + 1] = stalls[j];
				stalls[j] = temp;
			}
		}
	}
	NODE adjascent[200];
	for (int i = 0; i < cow_num - 1; i++)
		adjascent[i].lft = stalls[i], adjascent[i].rht = stalls[i + 1];
	for (int j = 0; j < cow_num; j++) {
		for (int i = 0; i < cow_num - 2; i++) {
			if ((adjascent[i].rht - adjascent[i].lft) < (adjascent[i + 1].rht - adjascent[i + 1].lft)) {
				NODE temp = adjascent[i];
				adjascent[i] = adjascent[i + 1];
				adjascent[i + 1] = temp;
			}
		}
	}
	int max_length = stalls[cow_num - 1] - stalls[0] + 1;
	if (board_num_limit <= cow_num - 1) {
		for (int i = 0; i < board_num_limit - 1; i++)
			max_length -= (adjascent[i].rht - adjascent[i].lft - 1);
	} else {
		max_length = cow_num;
	}

	fprintf(fout, "%d\n", max_length);
	exit(0);
}
