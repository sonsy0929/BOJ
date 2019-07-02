/*
Knapsack 문제!
dp[i] = 가방의 최대 수용 무게가 i일 때 가질 수 있는 최대값
i라는 인덱스에서 아직 갱신되지 않은, dp[j - w[i]]의 값을 확인한다는 것은,
2차원 배열에서 dp[i - 1][j - w[i]]를 보는 것과 같다.
그런데, j값을 w[i] ~ K(최대 무게)까지 오름차순으로 보면,
dp[j - w[i]]값은 2차원으로 봤을 때, dp[i][j - 2 * w[i]] + v[i]일 수 있다.
이는 item을 중복해서 여러번 사용하는 결과!! (이 문제에서는 중복이 발생해서는 안됨!!)
*/

#include <cstdio>
#include <algorithm>
using namespace std;
int dp[100001], w[100], v[100];
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d %d", w + i, v + i);
    for (int i = 0; i < n; i++){
        for (int j = k; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    printf("%d\n", dp[k]);
}