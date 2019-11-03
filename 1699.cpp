#include <cstdio>
#include <algorithm>
using namespace std;
constexpr int MAXSIZE = 100'001;
int dp[MAXSIZE], N;
int main(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        dp[i] = i;
        for (int j = 2; j * j <= i; j++){
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    printf("%d\n", dp[N]);
}