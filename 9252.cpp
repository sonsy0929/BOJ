#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int main(){
    string a, b;
    cin >> a >> b;
    int aS = a.size(), bS = b.size();
    for (int i = 1; i <= aS; i++){
        for (int j = 1; j <= bS; j++){
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[aS][bS] << "\n";
    int i = aS, j = bS;
    string ans;
    while (dp[i][j]){
        if (dp[i][j] == dp[i-1][j]) i--;
        else if (dp[i][j] == dp[i][j-1]) j--;
        else {
            ans.push_back(a[i-1]);
            i--, j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}