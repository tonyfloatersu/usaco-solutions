/*
  ID: suhangt1
  PROG: fracdec
  LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);
	int div1, div2; cin >> div1 >> div2;
	set< pair< int, int > > stack_set;
	vector< pair< int, int > > stack;
	int outside = div1 / div2; div1 -= outside * div2;
	while (1) {
		int chk_ruse = stack_set.size();
		stack.push_back(make_pair(div1 * 10, div1 * 10 / div2));
		stack_set.insert(make_pair(div1 * 10, div1 * 10 / div2));
		div1 = div1 * 10 - (div1 * 10 / div2) * div2;
		if (chk_ruse == stack_set.size() || div1 == 0)
			break;
	}
	string answer;
	if (div1 != 0) {
		int re_start = 0;
		for (vector< pair< int, int > >::iterator it = stack.begin();
			 it != stack.end(); it++)
			if ((*it) == *(stack.end() - 1)) {
				re_start = it - stack.begin();
				break;
			}
		answer += to_string(outside);
		answer += '.';
		for (int i = 0; i < re_start; i++)
			answer += to_string(stack[i].second);
		answer += '(';
		for (int i = re_start; i < stack_set.size(); i++)
			answer += to_string(stack[i].second);
		answer += ')';
	} else {
		answer += to_string(outside);
		answer += '.';
		for (int i = 0; i < stack_set.size(); i++)
			answer += to_string(stack[i].second);
	}
	for (int i = 0; i < answer.length(); i++) {
		cout << answer[i];
		if ((i + 1) % 76 == 0)
			cout << endl;
	}
	if (answer.length() % 76 != 0)
		cout << endl;
	return 0;
}
