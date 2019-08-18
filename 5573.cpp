#include <cstdio>
using namespace std;
int dp[1001][1001], maze[1001][1001];
int main(){
    int H, W, N;
    scanf("%d %d %d", &H, &W, &N);
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            scanf("%d", &maze[i][j]);
        }
    }
    dp[0][0] = N - 1;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            int ref = dp[i][j];
            if (!ref) continue;
            dp[i+1][j] += ref / 2;
            dp[i][j+1] += ref / 2;
            if (ref % 2){
                if (maze[i][j]) dp[i][j+1]++;
                else dp[i+1][j]++;
            }
            maze[i][j] = (maze[i][j] + dp[i][j]) % 2;
        }
    }
    int r = 0, c = 0;
    while (r < H && c < W){
        if (maze[r][c]) c++;
        else r++;
    }
    printf("%d %d\n", r + 1, c + 1);
}