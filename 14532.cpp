#include <cstdio>
#include <algorithm>
using namespace std;
int LU_R[10], LU_C[10], RD_R[10], RD_C[10], color[11][11];
bool possible[10];
int main(){
    int n;
    scanf("%d", &n);
    fill(LU_R, LU_R+10, 10);
    fill(LU_C, LU_C+10, 10);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int curr;
            scanf("%1d", &curr);
            if (!curr) continue;
            color[i][j] = curr;
            possible[curr] = true;
            LU_R[curr] = min(i, LU_R[curr]);
            LU_C[curr] = min(j, LU_C[curr]);
            RD_R[curr] = max(i, RD_R[curr]);
            RD_C[curr] = max(j, RD_C[curr]);
        }
    }
    for (int i = 1; i <= 9; i++){
        for (int r = LU_R[i]; r <= RD_R[i]; r++){
            for (int c = LU_C[i]; c <= RD_C[i]; c++){
                if (i == color[r][c]) continue;
                possible[color[r][c]] = false;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 9; i++) ans += possible[i];
    printf("%d\n", ans);
}