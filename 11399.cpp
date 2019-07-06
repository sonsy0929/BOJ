#include <cstdio>
#include <algorithm>
using namespace std;
int n, t[1000];
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", t + i);
    int ans = 0, prev = 0;
    sort(t, t + n);
    for (int i = 0; i < n; i++) {
        int cost = prev + t[i];
        ans += cost;
        prev = cost;
    }
    printf("%d\n", ans);
}