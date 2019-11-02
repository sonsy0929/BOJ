#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1000], v[1000], n;
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", v+i);
    for (int i = 0; i < n; i++){
        if (!dp[i]) dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (v[i] > v[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    printf("%d\n", *max_element(dp, dp + n));
}