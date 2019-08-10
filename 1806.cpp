#include <cstdio>
#include <algorithm>
using namespace std;
int in[100'001];
int main(){
    int N, S;
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++) scanf("%d", in + i);
    int sum = 0, lo = 0, hi = 0;
    int ans = 1e9;
    while (hi <= N){
        if (sum < S) sum += in[hi++];
        else {
            ans = min(ans, hi - lo);
            sum -= in[lo++];
        }
    }
    printf("%d\n", ans != 1e9 ? ans : 0);
}