#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N, L, door[25], dp[25][25];
int f(int a, int b){
    int curr = max(a,b) + 1;
    if (curr >= L + 2) return 0;
    int &ret = dp[a][b];
    if (ret != -1) return ret;
    int aRet = f(curr, b) + abs(door[curr] - door[a]);
    int bRet = f(a, curr) + abs(door[curr] - door[b]);
    return ret = min(aRet, bRet);
}
int main(){
    scanf("%d %d %d %d", &N, &door[0], &door[1], &L);
    for (int i = 2; i < L + 2; i++) {
        scanf("%d", door + i);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(0, 1));
}