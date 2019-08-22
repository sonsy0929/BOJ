#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;
int n, k, pSum[101];
int main(){
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++){
        int in;
        scanf("%d", &in);
        pSum[i] = pSum[i-1] + in;
    }
    int ans = -INF;
    for (int i = 0; i + k <= n; i++){
        ans = max(ans, pSum[i + k] - pSum[i]);
    }
    printf("%d\n", ans);
}