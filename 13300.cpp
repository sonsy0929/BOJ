#include <cstdio>
using namespace std;
int m[7], f[7];
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        int s, y;
        scanf("%d %d", &s, &y);
        if (s == 0) f[y]++;
        else m[y]++;
    }
    int ans = 0;
    for (int i = 1; i <= 6; i++){
        ans += m[i] / k;
        ans += f[i] / k;
        if (m[i] % k) ans++;
        if (f[i] % k) ans++;
    }
    printf("%d\n", ans);
}