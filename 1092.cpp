#include <cstdio>
#include <algorithm>
using namespace std;
int crain[50], box[10000];
int main(){
    int N, M;
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
    int cnt[50]{};
    for (int i = M - 1; i >= 0; i--){
        int k = N - 1;
        for (int j = N - 2; j >= 0; j--){
            if (box[i] > crain[j]) break;
            if (cnt[k] > cnt[j]) k = j;
        }
        cnt[k]++;
    }
    printf("%d\n", *max_element(cnt, cnt + N));
}