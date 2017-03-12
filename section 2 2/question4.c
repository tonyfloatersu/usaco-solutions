/*
  ID: suhangt1
  LANG: C
  PROG: lamps
*/

#include <stdio.h>
#include <stdlib.h>

int status[10][10] = {
	{0, 0, 0, 0, 0, 0, 0}, // 3   c = 1 2 3 4
	{0, 0, 0, 1, 1, 1, 0}, // 24  c = 2 3 4
	{0, 0, 1, 0, 1, 0, 1}, // 1   c = 1 2 3 4
	{0, 0, 1, 1, 0, 1, 1}, // 4   c = 1 2 3 4
	{0, 1, 0, 0, 1, 0, 0}, // 34  c = 2 3 4
	{0, 1, 0, 1, 0, 1, 0}, // 2   c = 1 2 3 4
	{0, 1, 1, 0, 0, 0, 1}, // 14  c = 2 3 4
	{0, 1, 1, 1, 1, 1, 1}  // 0   c = 0 1 2 3 4
};

int main() {
	FILE *fin = fopen("lamps.in", "r");
	FILE *fout = fopen("lamps.out", "w");
	int lampnum; fscanf(fin, "%d", &lampnum);
	int temp_lampnum = lampnum;
	int bottom_press_count; fscanf(fin, "%d", &bottom_press_count);
	char lamps[105]; for (int i = 0; i < 105; i++) lamps[i] = -1;
	while (1) {
		int temp; fscanf(fin, "%d", &temp);
		if (temp != -1) {
			while (temp > 0) {
				lamps[temp] = 1;
				temp -= 6;
			}
		} else break;
	}
	while (1) {
		int temp; fscanf(fin, "%d", &temp);
		if (temp != -1) {
			while (temp > 0) {
				if (lamps[temp] == 1) {
					fprintf(fout, "IMPOSSIBLE\n");
					exit(0);
				}
				lamps[temp] = 0;
				temp -= 6;
			}
		} else break;
	}
	if (lampnum > 4)
		while (lampnum > 4)
			lampnum -= 2;
	int printcount = 0;
	for (int i = 0; i < 8; i++) {
		int validity = 1;
		for (int j = 1; j < 7; j++)
			if (lamps[j] != -1)
				if (status[i][j] != lamps[j]) {
					validity = 0;
					break;
				}
		int validity2 = 1;
		if ((i == 1 && bottom_press_count == 1) || (i == 1 && bottom_press_count == 0))
			validity2 = 0;
		else if ((i == 4 && bottom_press_count == 1) || (i == 4 && bottom_press_count == 0))
			validity2 = 0;
		else if ((i == 6 && bottom_press_count == 1) || (i == 6 && bottom_press_count == 0))
			validity2 = 0;
		else if (i != 7 && bottom_press_count == 0)
			validity2 = 0;
		if (validity && validity2) {
			for (int j = 0; j < temp_lampnum; j++)
				fprintf(fout, "%d", status[i][j % 6 + 1]);
			printcount++;
			fprintf(fout, "\n");
		}
		if (i == 7 && printcount == 0)	{
			fprintf(fout, "IMPOSSIBLE\n");
			exit(0);
		}
	}
	exit(0);
}
