#include <cstdio>
#include <algorithm>
using namespace std;
int N, cnt[100'001];
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        cnt[u]++, cnt[v]++;
    }
    printf("%d\n", *max_element(cnt, cnt + N) + 1);
}