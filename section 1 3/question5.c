/*
ID: suhangt1
LANG: C
PROG: wormhole
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 12

typedef struct place {
	int x;
	int y;
} PLC;

int existing_circle(int right_side[], int wormholes, int pair[]);

int solve(int pair[], int right_side[], int wormholes);

int main() {
	FILE *fin = fopen("wormhole.in", "r");
	FILE *fout = fopen("wormhole.out", "w");
	int wormholes; fscanf(fin, "%d", &wormholes);
	PLC place[1 + MAX_N];
	for (int i = 1; i <= wormholes; i++)
		fscanf(fin, "%d %d", &place[i].x, &place[i].y);
	int right_side[1 + MAX_N];
	for (int i = 0; i <= wormholes; i++)
		right_side[i] = 0;
	for (int i = 1; i <= wormholes; i++)
		for (int j = 1; j <= wormholes; j++)
			if (place[j].y == place[i].y && place[j].x > place[i].x)
				if (right_side[i] == 0
					|| place[j].x - place[i].x < place[right_side[i]].x - place[i].x)
					right_side[i] = j;
	int pair[1 + MAX_N];
	for (int i = 0; i < 1 + MAX_N; i++)
		pair[i] = 0;
	fprintf(fout, "%d\n", solve(pair, right_side, wormholes));
	exit(0);
}

int existing_circle(int right_side[], int wormholes, int pair[]) {
	for (int start = 1; start <= wormholes; start++) {
		int position = start;
		for (int i = 0; i < wormholes; i++)
			position = right_side[pair[position]];
		if (position != 0)
			return 1;
	}
	return 0;
}

int solve(int pair[], int right_side[], int wormholes) {
	int i, total = 0;
	for (i = 1; i <= wormholes; i++)
		if (pair[i] == 0)
			break;
	if (i > wormholes) {
		if (existing_circle(right_side, wormholes, pair))
			return 1;
		else
			return 0;
	}
	for (int j = i + 1; j <= wormholes; j++) {
		if (pair[j] == 0) {
			pair[i] = j, pair[j] = i;
			total += solve(pair, right_side, wormholes);
			pair[i] = pair[j] = 0;
		}
	}
	return total;
}
