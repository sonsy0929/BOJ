/*
�ð����⵵ : O(tc * L^2)
tc = �׽�Ʈ���̽�, L = ���ڿ��� ����

���� ���ڿ��̶� ��� D ���� �����ؾ� �Ѵ�.
��, �� D �ֿ��� �� ���̶� �ߺ��� �߻��ϸ� ���� ���ڿ��� �ƴϰ� �ȴ�.
�־����� �Է��� ���ĺ� �빮�ڸ� �־����Ƿ�, 0 ~ 25�� ���� ������ �� �־� [26][26] �迭�� �̿��ߴ�.
������ D �ֿ� ���ؼ� �� ���̶� �ߺ��� �߻��ϸ� isSurprising �Լ����� false�� ��ȯ�ϰ�,
�׷��� ������ true�� ��ȯ�ϴ� ������ ���踦 �ߴ�.
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