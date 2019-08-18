#include <cstdio>
using namespace std;
int dp[31][31];
void init(){
    for (int i = 1; i < 30; i++){
        dp[i][1] = i;
        dp[i][i] = 1;
    }
    for (int i = 2; i < 30; i++){
        for (int j = 2; j < 30; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1]; 
        }
    }
}
int main(){
    int T;
    scanf("%d", &T);
    init();
    while (T--){
        int N, M;
        scanf("%d %d", &N, &M);
        printf("%d\n", dp[M][N]);
    }
}