#include <cstdio>
#include <algorithm>
using namespace std;
int crain[50], box[10000];
int N, M;
bool isPossible(int param){
    int curr = N - 1;
    for (int i = M - 1; i >= 0; i -= param){
        if (curr < 0 || crain[curr] < box[i]) return false;
        curr--;
    }
    return true;
}
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", crain + i);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) scanf("%d", box + i);
    sort(crain, crain + N);
    sort(box, box + M);
    if (box[M-1] > crain[N-1]){
        puts("-1");
        return 0;
    }
    int lo = 0, hi = 10000;
    while (lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if (isPossible(mid)) hi = mid;
        else lo = mid;
    }
    printf("%d\n", hi);
}