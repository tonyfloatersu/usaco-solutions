/*
ID: suhangt1
LANG: C
PROG: ride
 */
#include <stdio.h>
#include <stdlib.h>

int ctoi(char bit);

int inscope(char bit);

int transform(char *command);

int main() {
	FILE *fin = fopen("ride.in", "r");
	FILE *fout = fopen("ride.out", "w");
	char command1[6], command2[6];
	fscanf(fin, "%s %s", command1, command2);
	if (transform(command1) == transform(command2))
		fprintf(fout, "GO\n");
	else
		fprintf(fout, "STAY\n");
	exit(0);
}

int ctoi(char bit) { return bit - 'A' + 1; }

int inscope(char bit) { return (bit >= 'A' && bit <= 'Z'); }

int transform(char *command) {
	int target = 1;
	for (int i = 0; i < 6; i++) {
		if (inscope(command[i]))
			target *= ctoi(command[i]);
		else
			break;
	}
	return target % 47;
}
