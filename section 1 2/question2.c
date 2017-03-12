/*
  ID: suhangt1
  LANG: C
  PROG: transform
 */

#include <stdio.h>
#include <stdlib.h>

int type_check_1(char (*cubes)[10][10], int size);

int type_check_2(char (*cubes)[10][10], int size);

int type_check_3(char (*cubes)[10][10], int size);

int type_check_4(char (*cubes)[10][10], int size);

int type_check_5(char (*cubes)[10][10], int size);

int type_check_6(char (*cubes)[10][10], int size);

int main() {
	FILE *fin = fopen("transform.in", "r");
	FILE *fout = fopen("transform.out", "w");
	char cube[2][10][10];
	int size;
	fscanf(fin, "%d", &size);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < size; j++)
			fscanf(fin, "%s", cube[i][j]);
	if (type_check_1(cube, size))
		fprintf(fout, "1\n");
	else if (type_check_2(cube, size))
		fprintf(fout, "2\n");
	else if (type_check_3(cube, size))
		fprintf(fout, "3\n");
	else if (type_check_4(cube, size))
		fprintf(fout, "4\n");
	else if (type_check_6(cube, size))
		fprintf(fout, "6\n");
	else if (type_check_5(cube, size))
		fprintf(fout, "5\n");
	else
		fprintf(fout, "7\n");
	exit(0);
}

int type_check_1(char (*cubes)[10][10], int size) {
	int result = 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (cubes[0][i][j] != cubes[1][j][size - 1 - i])
				result = 0;
	return result;
}

int type_check_2(char (*cubes)[10][10], int size) {
	int result = 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (cubes[0][i][j] != cubes[1][size - 1 - i][size - 1 - j])
				result = 0;
	return result;
}

int type_check_3(char (*cubes)[10][10], int size) {
	int result = 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (cubes[0][i][j] != cubes[1][size - 1 - j][i])
				result = 0;
	return result;
}

int type_check_4(char (*cubes)[10][10], int size) {
	int result = 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (cubes[0][i][j] != cubes[1][i][size - 1 - j])
				result = 0;
	return result;
}

int type_check_5(char (*cubes)[10][10], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < (int)(size / 2); j++) {
			char temp = cubes[0][i][j];
			cubes[0][i][j] = cubes[0][i][size - 1 - j];
			cubes[0][i][size - 1 - j] = temp;
		}
	}
	if (type_check_1(cubes, size) || type_check_2(cubes, size) || type_check_3(cubes, size))
		return 1;
	else
		return 0;
}

int type_check_6(char (*cubes)[10][10], int size) {
	int result = 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (cubes[0][i][j] != cubes[1][i][j])
				result = 0;
	return result;
}
