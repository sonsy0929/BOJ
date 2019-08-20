#include <cstdio>
using namespace std;
const int SIZE = 100'001;
int pSum[SIZE];
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        int in;
        scanf("%d", &in);
        pSum[i] = pSum[i - 1] + in;
    }
    for (int i = 1; i <= M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", pSum[v] - pSum[u - 1]);
    }
}