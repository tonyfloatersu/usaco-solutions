#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>
#define CODE_WORKS true
using namespace std;
ifstream in("cowtour.in");
ofstream out("cowtour.out");

int N;

struct Node{
    int x, y;
};
typedef vector<int> Vb;
typedef vector<vector<double> > Dg;
vector<Node> past;

double distan(int a, int b){
    return sqrt((past[b].x - past[a].x) * (past[b].x - past[a].x)
				+ (past[b].y - past[a].y) * (past[b].y - past[a].y));
}

void path(vector<Vb> a, double (&dist)[150][150]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) dist[i][j] = 0;
            else if(a[i][j]) dist[i][j] = distan(i, j);
            else dist[i][j] = INFINITY;
        }
    }
    for(int k = 0; k < N; k++){
        for(int j = 0; j < N; j++){
            for(int i = 0; i < N; i++){
                if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

double longest(double (&paths)[150]){
    double big = 0;
    for(int i = 0; i < N; i++){
        if(paths[i] != INFINITY && paths[i] > big)
			big = paths[i];
    }
    return big;
}

int main(){
	freopen("cowtour_.out", "w", stdout);
	int i, j, k, l, x, y;
    string row;
    in >> N;
    past.resize(N);
    for(i = 0; i < N; i++) in >> past[i].x >> past[i].y;
    vector<Vb> a(N, Vb(N)); //Adjacency matrix
    Vb v(N); //Visited matrix for flood fill
    for(i = 0; i < N; i++){
        in >> row;
        for(j = 0; j < N; j++){
            if(row[j] == '0') a[i][j] = 0;
            else a[i][j] = 1;
        }
        v[i] = 0; //Setting all pastures as unvisited
    }
    double dists[150][150];
    path(a, dists);
    double smallest = INFINITY;
    for(k = 0; k < N; k++){
        for(l = 0; l < N; l++){
            if(k == l || dists[k][l] != INFINITY) continue;
            smallest = min(smallest, longest(dists[k]) + distan(k, l) + longest(dists[l]));
        }
    }
    for(k = 0; k < N; k++){
        smallest = max(smallest, longest(dists[k]));
    }
    printf("%.6lf\n", smallest);
    return 0;
}
