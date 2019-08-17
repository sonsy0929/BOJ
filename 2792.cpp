#include <cstdio>
#include <algorithm>
using namespace std;
int N, M, color[300'000];
bool isPossible(int m){
    int cnt = 0;
    for (int i = 0; i < M; i++){
        cnt += (color[i] - 1) / m + 1;
    }
    return cnt <= N;
}
int main(){
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) scanf("%d", color + i);
    int lo = 0, hi = 1e9;
    while (lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if (isPossible(mid)) hi = mid;
        else lo = mid;
    }
    printf("%d\n", hi);
}