/*
������ �κй����� ������ �ذ��ϴ� ������� Ǯ����.
�ùٸ� �ܾ��̷���, 1) ������ 'w'�� ���� 2) wolf�� ���ӵǰ� ���� n����ŭ ���;� �Ѵ�.
�� ���� �����ϰ� �����ϸ� �ȴ�. �κй����� ������ �����ϴ� ���� �����ϱ� ���� ��������.
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