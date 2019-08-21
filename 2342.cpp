#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[100'000][5][5];
vector<int> ddr;
int f(int pos, int l, int r){
    if (pos == ddr.size()) return 0;
    int &ret = dp[pos][l][r];
    if (ret != -1) return ret;
    if (!l && !r) return ret = f(pos + 1, ddr[pos], r) + 2;
    if (l == ddr[pos]) return ret = f(pos + 1, l, r) + 1;
    if (r == ddr[pos]) return ret = f(pos + 1, l, r) + 1;
    int left, right;
    int next = ddr[pos];
    
    if (!r) right = f(pos + 1, l, next) + 2;       
    else if (abs(next - r) == 2) right = f(pos + 1, l, next) + 4;
    else right = f(pos + 1, l, next) + 3;
    
    if (!l) left = f(pos + 1, next, r) + 2;
    else if (abs(next - l) == 2) left = f(pos + 1, next, r) + 4;
    else left = f(pos + 1, next, r) + 3;
    
    return ret = min(left, right);
}
int main(){
    int in;
    for (scanf("%d", &in); in != 0; scanf("%d", &in)) ddr.push_back(in);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(0, 0, 0));
}