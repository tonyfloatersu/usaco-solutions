/*
ID: suhangt1
PROG: zerosum
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int eval(string answer) {
    // eval the answer string into the result number
    int result = 0;
    for (string::iterator it = answer.begin(); it <= answer.end(); it++)
        if (*it == ' ')
            answer.erase(it);
    string::size_type temp;
    while (1) {
        result += stoi(answer, &temp, 10);
        answer = answer.substr(temp);
        if (answer.length() == 0)
            break;
    }
    return result;
}

int main() {
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    int val; cin >> val;
    /* use the violent method, 3 ^ (n - 1) to search */
    for (int mode = 0; mode < (int) pow(3, val - 1); mode++) {
        string answer; int num = 1, test = mode;
        while (num <= val) {
            answer += (char) (num + '0');
            num++;
            if (num > val) break;
            answer += (test % 3 == 0) ? '+' : (test % 3 == 1) ? '-' : ' ';
            test /= 3;
        }
        if (!eval(answer))
            cout << answer << endl;
    }
    return 0;
}
