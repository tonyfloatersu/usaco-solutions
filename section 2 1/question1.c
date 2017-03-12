/*
ID: suhangt1
PROG: castle
LANG: C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WEST 0
#define NORTH 1
#define EAST 2
#define SOUTH 3

#define max(a, b) ((a) > (b)) ? (a) : (b)

typedef struct node {
	int west;
	int north;
	int east;
	int south;
} NODE;

NODE transfer(int num);

void dfs(int (*wall)[60][5], int row, int col, int noti);

int main() {
	FILE *fin = fopen("castle.in", "r");
	FILE *fout = fopen("castle.out", "w");
	int cols, rows; fscanf(fin, "%d %d", &cols, &rows);
	int walls[60][60][5];
	for (int i = 0; i < 60; i++)
		for (int j = 0; j < 60; j++)
			for (int k = 0; k < 5; k++)
				walls[i][j][k] = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			int temp_room; fscanf(fin, "%d", &temp_room);
			NODE temp = transfer(temp_room);
			walls[i][j][WEST] = temp.west;
			walls[i][j][NORTH] = temp.north;
			walls[i][j][EAST] = temp.east;
			walls[i][j][SOUTH] = temp.south;
		}
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			dfs(walls, i, j, 1 + i * cols + j);
	int counter_arr[cols * rows]; memset(counter_arr, 0, cols * rows * sizeof(int));
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			counter_arr[walls[i][j][4] - 1]++;
	int room_count = 0;
	for (int i = 0; i < rows * cols; i++)
		if (counter_arr[i])
			room_count++;
	fprintf(fout, "%d\n", room_count);
	int max_size_room = 0;
	for (int i = 0; i < rows * cols - 1; i++)
		max_size_room = max(counter_arr[i], max_size_room);
	fprintf(fout, "%d\n", max_size_room);
	// try to find the area | wall place and -- wall place
	// priority | then --
	int coord_y = 0, coord_x = 0, max_size_room_1 = 0;
	for (int i = 1; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			if (walls[i][j][4] != walls[i - 1][j][4]) {
				if (max_size_room_1
					< counter_arr[walls[i][j][4] - 1] + counter_arr[walls[i - 1][j][4] - 1])
					max_size_room_1
						= counter_arr[walls[i][j][4] - 1] + counter_arr[walls[i - 1][j][4] - 1],
						coord_y = i, coord_x = j;
				else if (max_size_room_1
						 == counter_arr[walls[i][j][4] - 1] + counter_arr[walls[i - 1][j][4] - 1]) {
					if (coord_x >= j)
						coord_x = j, coord_y = i;
				}
			}
		}
	int coord_y2 = 0, coord_x2 = 0, max_size_room_2 = 0;
	for (int i = 0; i < rows; i++)
		for (int j = cols - 2; j > - 1; j--) {
			if (walls[i][j][4] != walls[i][j + 1][4]) {
				if (max_size_room_2
					< counter_arr[walls[i][j][4] - 1] + counter_arr[walls[i][j + 1][4] - 1])
					max_size_room_2
						= counter_arr[walls[i][j][4] - 1] + counter_arr[walls[i][j + 1][4] - 1],
						coord_y2 = i, coord_x2 = j;
				else if (max_size_room_2
						 == counter_arr[walls[i][j][4] - 1] + counter_arr[walls[i][j + 1][4] - 1]) {
					if (coord_x2 >= j)
						coord_x2 = j, coord_y2 = i;
				}
			}
		}
	if (max_size_room_1 > max_size_room_2) {
		fprintf(fout, "%d\n", max_size_room_1);
		fprintf(fout, "%d %d N\n", coord_y + 1, coord_x + 1);
	} else if (max_size_room_1 < max_size_room_2) {
		fprintf(fout, "%d\n", max_size_room_2);
		fprintf(fout, "%d %d E\n", coord_y2 + 1, coord_x2 + 1);
	} else {
	// find the coordinate that make it largest and most west south direction
		fprintf(fout, "%d\n", max_size_room_2);
		if (coord_x < coord_x2)
			fprintf(fout, "%d %d N\n", coord_y + 1, coord_x + 1);
		else if (coord_x > coord_x2)
			fprintf(fout, "%d %d E\n", coord_y2 + 1, coord_x2 + 1);
		else {
			// if coord_x == coord_x2
			if (coord_y2 < coord_y)
				fprintf(fout, "%d %d N\n", coord_y + 1, coord_x + 1);
			else if (coord_y2 > coord_y)
				fprintf(fout, "%d %d E\n", coord_y2 + 1, coord_x2 + 1);
			else
				fprintf(fout, "%d %d N\n", coord_y2 + 1, coord_x2 + 1);
		}
	}
	exit(0);
}

NODE transfer(int num) {
	NODE temp;
	temp.west = (num % 2 == 1);
	num -= (num % 2 == 1);
	temp.south = (num >= 8);
	num -= (num >= 8) * 8;
	temp.east = (num >= 4);
	num -= (num >= 4) * 4;
	temp.north = (num >= 2);
	num -= (num >= 2) * 2;
	return temp;
}

void dfs(int (*wall)[60][5], int row, int col, int noti) {
	// if the point is visited, return
	if (wall[row][col][4] != 0) return;
	else {
		wall[row][col][4] = noti;
		if (wall[row][col][EAST] == 0)
			dfs(wall, row, col + 1, noti);
		if (wall[row][col][WEST] == 0)
			dfs(wall, row, col - 1, noti);
		if (wall[row][col][NORTH] == 0)
			dfs(wall, row - 1, col, noti);
		if (wall[row][col][SOUTH] == 0)
			dfs(wall, row + 1, col, noti);
	}
}
