#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int SIZE = 500;
int N,K, dp[SIZE][SIZE];
vector<p> dot;
int getDist(p u, p v){
    return abs(u.first - v.first) + abs(u.second - v.second);
}
int f(int pos, int cnt){
    if (pos == N-1) return 0;
    int &ret = dp[pos][cnt];
    if (ret != -1) return ret;
    ret = f(pos+1, cnt) + getDist(dot[pos], dot[pos+1]);
    for (int i = 1; i <= cnt; i++){
        if (pos+i > N-1) continue;
        ret = min(ret, f(pos+i+1, cnt-i) + getDist(dot[pos], dot[pos+i+1]));
    }
    return ret;
}
int main(){
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        dot.push_back({u, v});
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(0, K));
}