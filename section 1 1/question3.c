/*
ID: suhangt1
PROG: gift1
LANG: C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_name(char dictionary[][20], int name_quantity, char name_target[]);

int left_over(int quantity, int target_num);

int give_over(int quantity, int target_num);

int main() {
	FILE *fin = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");
	int person_num;
	fscanf(fin, "%d", &person_num);
	char person_name[10][20];
	for (int i = 0; i < person_num; i++)
		fscanf(fin, "%s", person_name[i]);
	int money_pocket[10];
	for (int i = 0; i < person_num; i++)
		money_pocket[i] = 0;
	for (int i = 0; i < person_num; i++) {
		char giver_temp[20];
		fscanf(fin, "%s", giver_temp);
		int giver_plc_temp = find_name(person_name, person_num, giver_temp);
		int quantity, target_num;
		fscanf(fin, "%d %d", &quantity, &target_num);
		money_pocket[giver_plc_temp]
			= money_pocket[giver_plc_temp] - quantity + left_over(quantity, target_num);
		for (int i = 0; i < target_num; i++) {
			char taker_temp[20];
			fscanf(fin, "%s", taker_temp);
			int taker_plc_temp = find_name(person_name, person_num, taker_temp);
			money_pocket[taker_plc_temp] += give_over(quantity, target_num);
		}
	}
	for (int i = 0; i < person_num; i++)
		fprintf(fout, "%s %d\n", person_name[i], money_pocket[i]);
	exit(0);
}

int find_name(char dictionary[][20], int name_quantity, char name_target[]) {
	for (int i = 0; i < name_quantity; i++)
		if (strcmp(dictionary[i], name_target) == 0)
			return i;
	return -1;
}

int left_over(int quantity, int target_num) {
	if (target_num != 0)
		return quantity % target_num;
	else
		return quantity;
}

int give_over(int quantity, int target_num) {
	if (target_num != 0)
		return (quantity - left_over(quantity, target_num)) / target_num;
	else
		return 0;
}
