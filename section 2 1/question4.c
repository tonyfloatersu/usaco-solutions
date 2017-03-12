/*
ID: suhangt1
LANG: C
PROG: holstein
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define min(a, b) ((a) < (b)) ? (a) : (b)

int main() {
	FILE *fin = fopen("holstein.in", "r");
	FILE *fout = fopen("holstein.out", "w");
	int vitamin_types; fscanf(fin, "%d", &vitamin_types);
	int vitamin_min_requirement[30];
	for (int i = 0; i < vitamin_types; i++)
		fscanf(fin, "%d", &vitamin_min_requirement[i]);
	int available_type_feed_num; fscanf(fin, "%d", &available_type_feed_num);
	int available_type_feed[20][30];
	for (int i = 0; i < available_type_feed_num; i++)
		for (int j = 0; j < vitamin_types; j++)
			fscanf(fin, "%d", &available_type_feed[i][j]);
	int total_conditons = (int)pow(2, available_type_feed_num);
	int solution[50000], solution_num = 0;
	for (int i = 0; i < total_conditons; i++) {
		int alias_i = i, temp_compare[30], digit = 0;
		for (int i = 0; i < 30; i++) temp_compare[i] = 0;
		while (alias_i > 0)	alias_i /= 2, digit++;
		alias_i = i;
		for (int k = 0; k < digit; k++) {
			if (alias_i - (alias_i / 2) * 2)
				for (int j = 0; j < vitamin_types; j++)
					temp_compare[j] += available_type_feed[k][j];
			alias_i /= 2;
		}
		int satisfy_count = 0;
		for (int k = 0; k < vitamin_types; k++) {
			if (temp_compare[k] < vitamin_min_requirement[k])
				break;
			else
				satisfy_count++;
			if (satisfy_count == vitamin_types) {
				solution[solution_num] = i;
				solution_num++;
			}
		}
	}
	int least = 100000;
	for (int i = 0; i < solution_num; i++) {
		int temp = solution[i], length = 0;
		while (temp > 0) {
			if (temp - (temp / 2) * 2)
				length++;
			temp /= 2;
		}
		least = min(length, least);
	}
	fprintf(fout, "%d ", least);
	int sol = 0;
	for (int i = 0; i < solution_num; i++) {
		int temp = solution[i], length = 0;
		while (temp > 0) {
			if (temp - (temp / 2) * 2)
				length++;
			temp /= 2;
		}
		if (length == least) {
			sol = solution[i];
			break;
		}
	}
	int start = 1, printtime = 1;
	while (sol > 0) {
		if (sol - (sol / 2) * 2) {
			fprintf(fout, "%d", start);
			printtime = 0;
		}
		start++;
		sol /= 2;
		if (sol > 0 && printtime == 0) {
			fprintf(fout, " ");
			printtime = 1;
		} else if (sol == 0) {
			fprintf(fout, "\n");
			break;
		}
	}
	exit(0);
}
