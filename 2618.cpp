#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
int N, W, dp[1002][1002];
int chk[1002][1002];
p incident[1002];
int getDist(p curr, p next){
    return abs(curr.first - next.first) + abs(curr.second - next.second);
}
int f(int a, int b){
    int curr = max(a,b) + 1;
    if (curr == W + 2) return 0;
    int &ret = dp[a][b];
    if (ret != -1) return ret;
    ret = f(curr, b) + getDist(incident[a], incident[curr]);
    int yRet = f(a, curr) + getDist(incident[b], incident[curr]);
    if (yRet < ret) {
        ret = yRet;
        chk[a][b] = 1;
    }
    return ret;
}
int main(){
    scanf("%d %d", &N, &W);
    incident[0] = {1, 1};
    incident[1] = {N, N};
    for (int i = 2; i < W + 2; i++){
        int r, c;
        scanf("%d %d", &r, &c);
        incident[i] = {r, c};
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(0, 1));
    for (int a = 0, b = 1; max(a,b) + 1 < W + 2;){
        printf("%d\n", chk[a][b] + 1);
        chk[a][b] ? b = max(a,b) + 1 : a = max(a,b) + 1;
    }
}