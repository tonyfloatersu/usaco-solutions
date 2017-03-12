/*
  ID: suhangt1
  LANG: C
  PROG: prefix
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)

int valid(int current, char str[200005], char prefix[15]);

int main() {
	FILE *fin = fopen("prefix.in", "r");
	FILE *fout = fopen("prefix.out", "w");
	char prefix_set[210][15];
	int counter = 0;
	while (1) {
		fscanf(fin, "%s", prefix_set[counter]);
		if (prefix_set[counter][0] == '.')
			break;
		counter++;
	}
	char str[200005], temp[100]; memset(temp, 0, 100 * sizeof(char));
	while (!feof(fin)) {
		fscanf(fin, "%s", temp);
		strcat(str, temp);
		memset(temp, 0, sizeof(char) * 100);
	}
	char truth_table[200100]; memset(truth_table, 0, 200100 * sizeof(char)); truth_table[0] = 1;
	int length = 0;
	for (int i = 0; i < (int) strlen(str); i++)
		if (truth_table[i]) {
			length = i;
			for (int j = 0; j < counter; j++)
				if (valid(i, str, prefix_set[j]))
					truth_table[i + (int) strlen(prefix_set[j])] = 1;
		}
	if (truth_table[strlen(str)])
		length = strlen(str);
	fprintf(fout, "%d\n", length);
	exit(0);
}

int valid(int current, char str[200005], char prefix[15]) {
	for (int i = 0; i < (int) strlen(prefix); i++) {
		if (str[current + i] != prefix[i])
			return 0;
		if (current + i > (int) strlen(str))
			return 0;
	}
	return 1;
}
