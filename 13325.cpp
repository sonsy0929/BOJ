#include <cstdio>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int SIZE = 1 << 21;
int parentE[SIZE + 1];
int dfs(int curr, int bound){
    if (curr * 2 > bound) return 0;
    int left = 0, right = 0;
    left = dfs(curr * 2, bound) + parentE[curr * 2];
    right = dfs(curr * 2 + 1, bound) + parentE[curr * 2 + 1];
    if (left > right) parentE[curr * 2 + 1] += left - right;
    else parentE[curr * 2] += right - left;
    return max(left, right);
}
int main(){
    int k, cnt, bound;
    scanf("%d", &k);
    bound = (1 << (k + 1)) - 1;
    for (int i = 2; i <= bound; i++){
        int in;
        scanf("%d", &in);
        parentE[i] = in;
    }
    dfs(1, bound);
    int ans = 0;
    for (int i = 2; i <= bound; i++) ans += parentE[i];
    printf("%d\n", ans);
}