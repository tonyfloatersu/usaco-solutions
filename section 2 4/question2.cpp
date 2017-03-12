/*
  ID: suhangt1
  PROG: maze1
  LANG: C++11
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define __DEBUG__

using namespace std;

/* specify a type for entrance */
typedef struct entrance {
	pair<int, int> location;
	pair<int, int> direction;
} entra;

const pair<int, int> dir[4] = {
	make_pair(0, 1),
	make_pair(-1, 0),
	make_pair(0, -1),
	make_pair(1, 0)
};

void transfer(string maze_pic[], int height, int width,
			  string (*maze_data)[100], entra entrance[2]) {
	/* initialize the block of maze directions */
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			int maze_loc_height = 2 * i + 1;
			int maze_loc_width = 2 * j + 1;
			maze_data[i][j] += char((maze_pic[maze_loc_height][maze_loc_width - 1] == '|') + '0');
			maze_data[i][j] += char((maze_pic[maze_loc_height - 1][maze_loc_width] == '-') + '0');
			maze_data[i][j] += char((maze_pic[maze_loc_height][maze_loc_width + 1] == '|') + '0');
			maze_data[i][j] += char((maze_pic[maze_loc_height + 1][maze_loc_width] == '-') + '0');
		}
	/* entrance notation and write the entrance information to outside */
	int static_count = 0;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			if (i == 0 && maze_data[i][j][1] == '0')
				maze_data[i][j] += '1';
			else if (i == height - 1 && maze_data[i][j][3] == '0')
				maze_data[i][j] += '3';
			else if (j == 0 && maze_data[i][j][0] == '0')
				maze_data[i][j] += '0';
			else if (j == width - 1 && maze_data[i][j][2] == '0')
				maze_data[i][j] += '2';
			else continue;
			if (maze_data[i][j].length() == 5) {
				entrance[static_count].direction = dir[maze_data[i][j][4] - '0'];
				entrance[static_count].location = make_pair(i, j);
				static_count++;
			}
		}
}

void max_length(string (*maze_data)[100], int (*_map)[100], int width, entra current, int weight) {
	if (weight != 0)
		_map[current.location.first][current.location.second] = weight + 1;
	// next dfs weight = the current _map[i][j] weight
	int one_count = 0;
	for (int i = 0; i < 4; i++)
		one_count += (maze_data[current.location.first][current.location.second][i] == '1');
	if (one_count == 3)
		return;
	// use the current one count to see whether there is still ways to go.

}

int main() {
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
	int width, height; cin >> width >> height;
	string maze_pic[2 * height + 1];
	string buffer; getline(cin, buffer);
	for (int i = 0; i < 2 * height + 1; i++)
		getline(cin, maze_pic[i]);
	/* left, right, up, down */
	string maze_data[height][100]; entra entrance[2];
	transfer(maze_pic, height, width, maze_data, entrance);
	/* preparation for the first entrance */
	int entrance1[height][100];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < 100; j++)
			entrance1[i][j] = 1;
	/* find the first entrance then close it */
#ifdef __DEBUG__
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			cout << maze_data[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < 2; i++) {
		cout << entrance[i].location.first << " " << entrance[i].location.second
			 << " " << entrance[i].direction.first << " " << entrance[i].direction.second
			 << endl;
	}
#endif
	
	return 0;
}
