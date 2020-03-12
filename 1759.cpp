/*
시간복잡도 : O(c_Comb_l)

문자의 종류 c가지 중에서 l개를 뽑아 자음2, 모음1개의 패스워드를 만족하는지 검사하고,
만족하면 패스워드를 저장하는 벡터에 넣어준다. 이후 정렬하고 출력
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
bool isValid(set<char>& param) {
    int cnt = 0;
    for (char c : param) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
    }
    return cnt >= 1 && param.size() - cnt >= 2;
}
int main() {
    fastio;
    int L, C;
    cin >> L >> C;
    vector<char> v(C);
    vector<int> permu(C, 0);
    cin.ignore();
    for (int i = 0; i < C; i++) cin >> v[i];
    for (int i = C - L; i < C; i++) permu[i] = 1;
    vector<string> ans;
    do {
        set<char> password;
        for (int i = 0; i < C; i++) {
            if (permu[i]) password.insert(v[i]);
        }
        string out;
        if (isValid(password)) {
            for (char c : password) out += c;
            ans.push_back(out);
        }
    } while (next_permutation(permu.begin(), permu.end()));
    sort(ans.begin(), ans.end());
    for (auto s : ans) cout << s << "\n";
}