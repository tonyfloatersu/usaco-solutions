/*
  ID: suhangt1
  PROG: comehome
  LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

typedef struct path {
    int dist;
    int to_where;
    path() {}
    path(int _dist, int _to_where) {
        dist = _dist;
        to_where = _to_where;
    }
} path;

void djrsk(vector< path > _farm[], int _distance[], int start_plc) {
    if (_farm[start_plc].size() == 0) return;
    for (vector< path >::iterator it = _farm[start_plc].begin();
         it != _farm[start_plc].end(); it++) {
        if (_distance[(*it).to_where] < _distance[start_plc] + (*it).dist)
            continue;
        _distance[(*it).to_where] = min(_distance[(*it).to_where],
                                        _distance[start_plc] + (*it).dist);
        djrsk(_farm, _distance, (*it).to_where);
    }
}

int main() {
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
    int paths; cin >> paths;
    vector< path > _farm[200];
    /* create the map */
    for (int i = 0; i < paths; i++) {
        char temp1, temp2; int _dis;
        cin >> temp1 >> temp2 >> _dis;
        if (temp1 == temp2) continue;
        _farm[(int) temp1].push_back((path) {_dis, (int) temp2});
        _farm[(int) temp2].push_back((path) {_dis, (int) temp1});
    }
    int _distance[200]; for (int i = 0; i < 200; i++) _distance[i] = 0xfffffff;
    _distance[(int) 'Z'] = 0;
    djrsk(_farm, _distance, (int) 'Z');
    int min_dis = 0xfffffff, plc = 0;
    for (int i = 'A'; i < 'Z'; i++) {
        if (_distance[i] != 0xfffffff && _distance[i] < min_dis)
            min_dis = _distance[i], plc = i;
    }
    cout << (char) plc << " " << min_dis << endl;
    return 0;
}
