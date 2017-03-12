/*
  ID: suhangt1
  PROG: maze1
  LANG: C++11
*/

#include <bits/stdc++.h>

// #define __DEBUG__

using namespace std;

class block {
public:
	int dist;
	pair< int, int > location;
	bool is_entrance;
	bool visited;
	block *left, *right, *up, *down;
	block *prev;
	block(pair< int, int > _location = make_pair(0, 0)) {
		location = _location;
		visited = false;
		is_entrance = false;
		left = right = up = down = prev = NULL;
		dist = -1;
	};
	~block() {};
};

void flood_fill(block **maze_data, block *entrance) {
	if (entrance->right != NULL) {
		if ((entrance->right->dist > 0 && entrance->right->dist > entrance->dist + 1)
			|| (entrance->right->dist < 0)) {
			entrance->right->dist = entrance->dist + 1;
			flood_fill(maze_data, entrance->right);
		}
	}
	if (entrance->left != NULL) {
		if ((entrance->left->dist > 0 && entrance->left->dist > entrance->dist + 1)
			|| (entrance->left->dist < 0)) {
			entrance->left->dist = entrance->dist + 1;
			flood_fill(maze_data, entrance->left);
		}
	}
	if (entrance->up != NULL) {
		if ((entrance->up->dist > 0 && entrance->up->dist > entrance->dist + 1)
			|| (entrance->up->dist < 0)) {
			entrance->up->dist = entrance->dist + 1;
			flood_fill(maze_data, entrance->up);
		}
	}
	if (entrance->down != NULL) {
		if ((entrance->down->dist > 0 && entrance->down->dist > entrance->dist + 1)
			|| (entrance->down->dist < 0)) {
			entrance->down->dist = entrance->dist + 1;
			flood_fill(maze_data, entrance->down);
		}
	}
}

int main() {
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
	int width, height; cin >> width >> height;
	string maze_pic[2 * height + 1];

	/* initialize the maze_data blocks */
	block **maze_data; maze_data = new block* [height];
	for (int i = 0; i < height; i++)
		maze_data[i] = new block [width];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			maze_data[i][j].location = make_pair(i, j);

	/* take in the data */
	for (int i = 0; i < 2 * height + 2; i++) {
		if (i > 0) {
			getline(cin, maze_pic[i - 1]);
			if (maze_pic[i - 1].size() == 0)
				for (int j = 0; j < 2 * width + 2; j++)
					maze_pic[i - 1] += ' ';
		}
		else getline(cin, maze_pic[0]);
	}

	/* create the map */
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int loc_y = 2 * i + 1, loc_x = 2 * j + 1;
			/* up */
			if (maze_pic[loc_y - 1][loc_x] == ' ' && loc_y - 1 != 0)
				maze_data[i][j].up = &maze_data[i - 1][j];
			else if (maze_pic[loc_y - 1][loc_x] == ' ' && loc_y - 1 == 0)
				maze_data[i][j].is_entrance = true;
			/* right */
			if (maze_pic[loc_y][loc_x + 1] == ' ' && loc_x + 1 != 2 * width)
				maze_data[i][j].right = &maze_data[i][j + 1];
			else if (maze_pic[loc_y][loc_x + 1] == ' ' && loc_x + 1 == 2 * width)
				maze_data[i][j].is_entrance = true;
			/* left */
			if (maze_pic[loc_y][loc_x - 1] == ' ' && loc_x - 1 != 0)
				maze_data[i][j].left = &maze_data[i][j - 1];
			else if (maze_pic[loc_y][loc_x - 1] == ' ' && loc_x - 1 == 0)
				maze_data[i][j].is_entrance = true;
			/* down */
			if (maze_pic[loc_y + 1][loc_x] == ' ' && loc_y + 1 != 2 * height)
				maze_data[i][j].down = &maze_data[i + 1][j];
			else if (maze_pic[loc_y + 1][loc_x] == ' ' && loc_y + 1 == 2 * height)
				maze_data[i][j].is_entrance = true;
		}
	}

	/* count the entrance and make another prepare */
	vector< block * > entrances;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (maze_data[i][j].is_entrance)
				entrances.push_back(&maze_data[i][j]);

	/* debug mode! */
#ifdef __DEBUG__
	/* check whether the map is built completely */
	char **picture; picture = new char* [2 * height + 1];
	for (int i = 0; i <= 2 * height; i++) picture[i] = new char [2 * width + 1];
	for (int i = 0; i <= 2 * height; i++)
		for (int j = 0; j <= 2 * width; j++)
			picture[i][j] = ' ';
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int loc_y = 2 * i + 1, loc_x = 2 * j + 1;
			picture[loc_y][loc_x] = (maze_data[i][j].is_entrance) ? 'e' : 'b';
			picture[loc_y - 1][loc_x] = (maze_data[i][j].up == NULL) ? ' ' : '|';
			picture[loc_y + 1][loc_x] = (maze_data[i][j].down == NULL) ? ' ' : '|';
			picture[loc_y][loc_x + 1] = (maze_data[i][j].right == NULL) ? ' ' : '-';
			picture[loc_y][loc_x - 1] = (maze_data[i][j].left == NULL) ? ' ' : '-';
		}
	}
	for (int i = 0; i <= 2 * height; i++) {
		for (int j = 0; j <= 2 * width; j++)
			cout << picture[i][j];
		cout << endl;
	}

	/* check whether the entrance vector is complete */
	cout << entrances.size() << endl;
#endif

	/* try the flood fill to get the first database */
	maze_data[entrances[0]->location.first][entrances[0]->location.second].dist = 1;
	flood_fill(maze_data, entrances[0]);
	int **data_base_1; data_base_1 = new int * [height];
	for (int i = 0; i < height; i++) data_base_1[i] = new int [width];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			data_base_1[i][j] = maze_data[i][j].dist;

	/* debug mode! */
#ifdef __DEBUG__
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			cout << setw(4) << data_base_1[i][j] << " ";
		cout << endl;
	}
#endif

	/* if there is just one entrance, then stop searching */
	int max_val = 0;
	if (entrances.size() == 1) {
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				if (max_val < data_base_1[i][j])
					max_val = data_base_1[i][j];
		cout << max_val << endl;
	}
	/* the rest can be finished in the morning, let me have a rest */
	else {
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				maze_data[i][j].dist = -1;
		maze_data[entrances[1]->location.first][entrances[1]->location.second].dist = 1;
		flood_fill(maze_data, entrances[1]);
		int **data_base_2; data_base_2 = new int * [height];
		for (int i = 0; i < height; i++) data_base_2[i] = new int [width];
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				data_base_2[i][j] = maze_data[i][j].dist;
#ifdef __DEBUG__
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++)
				cout << setw(4) << data_base_2[i][j] << " ";
			cout << endl;
		}
#endif
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				data_base_1[i][j] = min(data_base_1[i][j], data_base_2[i][j]);
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				if (max_val < data_base_1[i][j])
					max_val = data_base_1[i][j];
		cout << max_val << endl;
	}
	return 0;
}
