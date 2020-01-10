#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int matchs[4][4]{};
    for (int i = 0; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        matchs[u][v]++;
    }
    int A = matchs[1][2] + matchs[2][3] + matchs[3][1];
    int B = matchs[1][3] + matchs[3][2] + matchs[2][1];
    printf("%d\n", max(A, B));
}