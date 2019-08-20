#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, square[1001][1001], dp[1001][1001];
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%1d", &square[i][j]);
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (square[i][j]){
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
        }
    }
    int mxLen = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            mxLen = max(mxLen, dp[i][j]);
        }
    }
    printf("%d\n", mxLen * mxLen);
}