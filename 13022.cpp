/*
문제를 부분문제로 나누어 해결하는 방식으로 풀었다.
올바른 단어이려면, 1) 시작이 'w'로 시작 2) wolf가 연속되게 각자 n번만큼 나와야 한다.
이 점을 유의하고 구현하면 된다. 부분문제로 나누어 생각하는 것을 연습하기 좋은 문제같다.
*/

#include <bits/stdc++.h>
using namespace std;
string in;
bool f(string s) {
    if (s.size() == 0) return true;
    int p = 0, sz = s.size();
    while (sz > p && s[p] == 'w') p++;
    if (!p || sz < p*4) return false;
    bool chk = true;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < 4; j++) {
            chk &= s[i+p*j] == "wolf"[j];
        }
    }
    if (!chk) return false;
    return f(s.substr(p*4, in.size()-p*4));
}
int main() {
    cin >> in;
    cout << f(in);
}