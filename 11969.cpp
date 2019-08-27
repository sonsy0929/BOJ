#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 100'001;
int N, Q, pSum[SIZE][4];
int main(){
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++){
        int in;
        scanf("%d", &in);
        pSum[i][in] = max(pSum[i][in], pSum[i-1][in] + 1);
        for (int j = 1; j <= 3; j++) pSum[i][j] = max(pSum[i][j], pSum[i-1][j]);
    }
    for (int i = 0; i < Q; i++){
        int a, b, ans[4];
        scanf("%d %d", &a, &b);
        for (int j = 1; j <= 3; j++) {
            ans[j] = pSum[b][j] - pSum[a-1][j];
            printf("%d ", ans[j]);
        }
        puts("");
    }
}