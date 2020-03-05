/*
시간복잡도 : O(tc * L^2)
tc = 테스트케이스, L = 문자열의 길이

놀라운 문자열이란 모든 D 쌍이 유일해야 한다.
즉, 각 D 쌍에서 한 번이라도 중복이 발생하면 놀라운 문자열이 아니게 된다.
주어지는 입력은 알파벳 대문자만 주어지므로, 0 ~ 25의 수로 매핑할 수 있어 [26][26] 배열을 이용했다.
각각의 D 쌍에 대해서 한 번이라도 중복이 발생하면 isSurprising 함수에서 false를 반환하고,
그렇지 않으면 true를 반환하는 식으로 설계를 했다.
*/

#include <bits/stdc++.h>
using namespace std;
bool isSurprising(string& in) {
    bool ret = true;
    int sz = in.size();
    for (int i = 1; i < sz; i++) {
        bool chk[26][26]{};
        for (int j = 0; i + j < sz; j++) {
            int u = in[j] - 'A';
            int v = in[i + j] - 'A';
            ret &= !chk[u][v];
            chk[u][v] = true;
        }
    }
    return ret;
}
int main() {
    // fast io
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string in;
    while (cin >> in) {
        if (in == "*") break;
        if (isSurprising(in)) {
            cout << in << " is surprising.\n";
        } else {
            cout << in << " is NOT surprising.\n";
        }
    }
}