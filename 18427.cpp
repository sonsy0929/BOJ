/*
시간복잡도 : O(nw)

입력이 까다로운 냅색 문제이다.
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
const int MOD = 10'007;
vector<int> block[50];
int N, M, H, k, dp[50][1001];
int f(int pos, int curr) {
    if (pos == N || curr > H) return curr == H;
    int &ret = dp[pos][curr];
    if (ret != -1) return ret;
    ret = f(pos + 1, curr);
    for (int w : block[pos]) {
        ret = (ret + f(pos + 1, curr + w)) % MOD;
    }
    return ret;
}
int main() {
    fastio;
    memset(dp, -1, sizeof(dp));
    cin >> N >> M >> H;
    cin.ignore();
    string in;
    for (int i = 0; i < N; i++) {
        getline(cin, in);
        stringstream ss;
        ss.str(in);
        while (ss >> k) block[i].push_back(k);
    }
    cout << f(0, 0);
}