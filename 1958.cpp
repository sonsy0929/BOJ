#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 101;
char s1[MAX], s2[MAX], s3[MAX];
int dp[MAX][MAX][MAX];
bool cmp(char a, char b, char c){
    return a == b && b == c;
}
int main(){
    scanf("%s %s %s", s1 + 1, s2 + 1, s3 + 1);
    int l1 = strlen(s1 + 1);
    int l2 = strlen(s2 + 1);
    int l3 = strlen(s3 + 1);
    for (int i = 1; i <= l1; i++){
        for (int j = 1; j <= l2; j++){
            for (int k = 1; k <= l3; k++){
                if (cmp(s1[i], s2[j], s3[k])) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= l1; i++){
        for (int j = 1; j <= l2; j++){
            for (int k = 1; k <= l3; k++){
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    printf("%d\n", ans);
}