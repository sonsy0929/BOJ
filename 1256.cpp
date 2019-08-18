#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int SIZE = 201;
int N, M, K;
int dp[SIZE][SIZE];
vector<char> ans;
void init(){
    for (int i = 0; i < SIZE; i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for (int i = 2; i < SIZE; i++){
        for (int j = 1; j < i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            if (dp[i][j] > 1e9) dp[i][j] = 1e9 + 1;
        }
    }
}
void f(int a, int z, int k){
    if (!a){
        for (int i = 0; i < z; i++) ans.push_back('z');
        return;
    }
    int piv = dp[a + z - 1][a - 1];
    if (piv >= k) {
        ans.push_back('a');
        f(a - 1, z, k);
    }
    else {
        ans.push_back('z');
        f(a, z - 1, k - piv);
    }
}
int main(){
    scanf("%d %d %d", &N, &M, &K);
    init();
    if (dp[N+M][N] < K) puts("-1");
    else {
        f(N, M, K);
        for (char c : ans) printf("%c", c);
    }
}