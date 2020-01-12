#include <iostream>
using namespace std;
int N, M, cow[100][2];
int main(){
    char in[100];
    int idx[128]{};
    scanf("%d %d", &N, &M);
    idx['A'] = 1, idx['C'] = 2, idx['G'] = 4, idx['T'] = 8;
    for (int k = 0; k < 2; k++){
        for (int i = 0; i < N; i++){
            scanf(" %s", in);
            for (int j = 0; j < M; j++){
                cow[j][k] |= idx[in[j]];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < M; i++){
        ans += !(cow[i][0] & cow[i][1]);
    }
    printf("%d\n", ans);
}