#include <iostream>
#include <algorithm>
using namespace std;
int dp[5001][5001];
int main(){
    string a, b;
    cin >> a >> b;
    int aS = a.size(), bS = b.size();
    for (int i = 1; i <= aS; i++){
        for (int j = 1; j <= bS; j++){
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= aS; i++){
        for (int j = 1; j <= bS; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}