#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;
int R, C, K, Arr[300][300], RSIZE, CSIZE;
bool isEnd() {
    if (Arr[R][C] == K) return false;
    if (RSIZE >= 100) return false;
    if (CSIZE >= 100) return false;
    return true;
}
void solve(bool flag) {
    int newArr[300][300]{};
    int mxSIZE = 0;
    int I = RSIZE, J = CSIZE;
    if (!flag) swap(I, J);
    for (int i = 0; i < I; i++) {
        int cnt[101]{};
        vector<p> sorted;
        for (int j = 0; j < J; j++) {
            if (flag) cnt[Arr[i][j]]++;
            else cnt[Arr[j][i]]++;
        }
        for (int j = 1; j <= 100; j++) {
            if (cnt[j]) sorted.push_back({cnt[j], j});
        }
        sort(sorted.begin(), sorted.end());
        mxSIZE = max(mxSIZE, (int)sorted.size() * 2);
        int pos = 0;
        for (auto [cnt, val] : sorted) {
            if (flag) {
                newArr[i][pos++] = val;
                newArr[i][pos++] = cnt;
            }
            else {
                newArr[pos++][i] = val;
                newArr[pos++][i] = cnt;
            }
        }
    }
    memcpy(Arr, newArr, sizeof(Arr));
    if (flag) CSIZE = mxSIZE;
    else RSIZE = mxSIZE;
}
int main() {
    int in;
    cin >> R >> C >> K;
    R--, C--;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> Arr[i][j];
        }
    }
    RSIZE = 3, CSIZE = 3;
    int t = 0;
    for (; t <= 100 && isEnd(); t++) {
        if (RSIZE >= CSIZE) solve(true);
        else solve(false);
    }
    if (t > 100) cout << -1;
    else cout << t;
}