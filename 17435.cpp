#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int SIZE = 200'001;
const int K = 20;
int S[SIZE][K];
int main(){
    int N, Q;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &S[i][1]);
    scanf("%d", &Q);
    for (int j = 2; j < K; j++){
        for (int i = 1; i <= N; i++){
            S[i][j] = S[S[i][j-1]][j-1];
        }
    }
    while(Q--){
        int n, x;
        scanf("%d %d", &n, &x);
        int u = x;
        for (int j = 1; n; j++){
            if (n % 2) u = S[u][j];
            n /= 2;
        }
        printf("%d\n", u);
    }
}