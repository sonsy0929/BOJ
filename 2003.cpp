#include <cstdio>
using namespace std;
int N, M, in[10001];
int main(){
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", in + i);
    int ans = 0, sum = 0;
    int lo = 0, hi = 0;
    while (hi <= N) {
        if (sum >= M) sum -= in[lo++];
        else sum += in[hi++];
        if (sum == M) ans++;
    }
    printf("%d\n", ans);
}