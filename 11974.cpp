#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 50'001;
int N, v[SIZE], L[7], R[7];
int main(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", v+i);
    fill(L, L+7, -1);
    L[0] = 0;
    int p = 0;
    for (int i = 1; i <= N; i++){
        p = (p + v[i]) % 7;
        R[p] = i;
        if (L[p] != -1) continue;
        L[p] = i;
    }
    int ans = 0;
    for (int i = 0; i < 7; i++){
        if (L[i] == -1) continue;
        ans = max(ans, R[i] - L[i]);
    }
    printf("%d\n", ans);
}