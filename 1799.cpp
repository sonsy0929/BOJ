#include <cstdio>
#include <algorithm>
using namespace std;
int N, result;
bool board[10][10], inc[20], dec[20];
void f(int r, int c, int cnt, bool color){
    result = max(result, cnt);
    if (c >= N){
        r++;
        c = color^(r%2);
    }
    if (r >= N) return;
    int I = r+c, D = N-(r-c);
    if (board[r][c] && !inc[I] && !dec[D]){
        inc[I] = dec[D] = true;
        f(r,c+2,cnt+1,color);
        inc[I] = dec[D] = false;
    }
    f(r,c+2,cnt,color);
}
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &board[i][j]);
        }
    }
    f(0,0,0,false);
    int ans = result;
    result = 0;
    f(0,1,0,true);
    ans+=result;
    printf("%d\n", ans);
}