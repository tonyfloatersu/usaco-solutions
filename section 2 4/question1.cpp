/*
  ID: suhangt1
  PROG: ttwo
  LANG: C++11
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

// #define __DEBUG__

using namespace std;

const pair<int, int> dire[4] = {
	make_pair(-1, 0),
	make_pair(0, 1),
	make_pair(1, 0),
	make_pair(0, -1)
};

pair<int, int> next_direction(char _map[][10],
							  pair<int, int> curr_loc, pair<int, int> curr_dire) {
	pair<int, int> temp = make_pair(curr_loc.first + curr_dire.first,
									curr_loc.second + curr_dire.second);
	if ((temp.first < 0) || (temp.first > 9) || (temp.second < 0) || (temp.second > 9) ||
		_map[temp.first][temp.second] == '*') {
		int curr_dire_plc = 0;
		for (int i = 0; i < 4; i++)
			if (dire[i] == curr_dire)
				curr_dire_plc = i;
		curr_dire_plc = (curr_dire_plc + 1) % 4;
		return dire[curr_dire_plc];
	} else
		return curr_dire;
}

int main() {
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
	char grid[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> grid[i][j];
	pair<int, int> cow, farmer;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (grid[i][j] == 'F')
				farmer = make_pair(i, j);
			if (grid[i][j] == 'C')
				cow = make_pair(i, j);
		}
	grid[farmer.first][farmer.second] = '.';
	grid[cow.first][cow.second] = '.';
	pair<int, int> farmer_dir = make_pair(-1, 0);
	pair<int, int> cow_dir = make_pair(-1, 0);
	for (int step = 1; step < 1000; step++) {
		if (farmer == cow) {
			cout << step - 1 << endl;
			return 0;
			break;
		}
		pair<int, int> farmer_dir_temp = next_direction(grid, farmer, farmer_dir);
		pair<int, int> cow_dir_temp = next_direction(grid, cow, cow_dir);
#ifdef __DEBUG__
		cout << "f " << farmer.first << " " << farmer.second
			 << " c " << cow.first << " " << cow.second << endl;
#endif
		if (farmer_dir_temp != farmer_dir)
			farmer_dir = farmer_dir_temp;
		else
			farmer.first += farmer_dir.first, farmer.second += farmer_dir.second;
		if (cow_dir_temp != cow_dir)
			cow_dir = cow_dir_temp;
		else
			cow.first += cow_dir.first, cow.second += cow_dir.second;
	}
	cout << 0 << endl;
	return 0;
}
