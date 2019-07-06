#include <cstdio>
using namespace std;
int n, k, money[10];
int main(){
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", money + i);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--){
        if (k / money[i] == 0) continue;
        ans += k / money[i];
        k %= money[i];
    }
    printf("%d\n", ans);   
}