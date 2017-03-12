/*
ID: suhangt1
LANG: C
PROG: milk
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct bid {
	int unit_price;
	int unit_available;
} BID;

int main() {
	FILE *fin = fopen("milk.in", "r");
	FILE *fout = fopen("milk.out", "w");
	int amount, farmer_num;
	fscanf(fin, "%d %d", &amount, &farmer_num);
	BID market[5005];
	for (int i = 0; i < farmer_num; i++)
		fscanf(fin, "%d %d", &market[i].unit_price, &market[i].unit_available);
	for (int i = 0; i < farmer_num; i++) {
		for (int j = 0; j < farmer_num - 1; j++) {
			if (market[j + 1].unit_price < market[j].unit_price) {
				BID temp = market[j];
				market[j] = market[j + 1];
				market[j + 1] = temp;
			}
		}
	}
	int buy = 0, price = 0;
	while (amount > 0) {
		if (amount > market[buy].unit_available) {
			amount -= market[buy].unit_available;
			price += market[buy].unit_available * market[buy].unit_price;
		} else {
			price += amount * market[buy].unit_price;
			amount = 0;
		}
		buy++;
	}
	fprintf(fout, "%d\n", price);
	exit(0);
}
