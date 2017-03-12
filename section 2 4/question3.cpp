/*
  ID: suhangt1
  PROG: cowtour
  LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

double dist(pair< double, double > a, pair< double, double > b) {
	return sqrt(pow(a.second - b.second, 2) + pow(a.first - b.first, 2));
}

double longest_among(double *distances, int storage) {
	double temp = -1;
	for (int i = 0; i < storage; i++)
		if (temp < distances[i] && distances[i] != INFINITY)
			temp = distances[i];
	return temp;
}

int main() {
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);

	/* input the pastures and connections */
	int pasture_num; cin >> pasture_num;
	vector< pair< double, double > > pastures;
	for (int i = 0; i < pasture_num; i++) {
		double temp1, temp2; cin >> temp1 >> temp2;
		pastures.push_back(make_pair(temp1, temp2));
	}
	bool **connection; connection = new bool * [pasture_num];
	for (int i = 0; i < pasture_num; i++) connection[i] = new bool [pasture_num];
	for (int i = 0; i < pasture_num; i++)
		for (int j = 0; j < pasture_num; j++) {
			char temp; cin >> temp;
			connection[i][j] = (temp == '1') ? true : false;
		}
	/* record the distance between any two points */
    double **dist_bt_pts; dist_bt_pts = new double * [pasture_num];
	for (int i = 0; i < pasture_num; i++) dist_bt_pts[i] = new double [pasture_num];
	for (int i = 0; i < pasture_num; i++)
		for (int j = 0; j < pasture_num; j++)
			dist_bt_pts[i][j] = (i == j) ? 0 :
				((connection[i][j]) ? dist(pastures[i], pastures[j]) : INFINITY);
	for (int j = 0; j < pasture_num; j++)
		for (int i = 0; i < pasture_num; i++)
			for (int k = 0; k < pasture_num; k++)
				if (dist_bt_pts[k][i] > dist_bt_pts[k][j] + dist_bt_pts[j][i])
					dist_bt_pts[k][i] = dist_bt_pts[k][j] + dist_bt_pts[j][i];
	/* by here we are almost done */
	double small_path = INFINITY;
	for (int i = 0; i < pasture_num; i++)
		for (int j = 0; j < pasture_num; j++) {
			if (i == j || dist_bt_pts[i][j] != INFINITY) continue;
			else {
				small_path = min(longest_among(dist_bt_pts[i], pasture_num) +
								 longest_among(dist_bt_pts[j], pasture_num) +
								 dist(pastures[i], pastures[j]), small_path);
			}
		}
	for (int i = 0; i < pasture_num; i++)
		small_path = max(small_path, longest_among(dist_bt_pts[i], pasture_num));
	printf("%6lf", small_path); cout << endl;
	return 0;
}
