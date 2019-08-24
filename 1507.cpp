#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int n, in;
    scanf("%d", &n);
    int dist[20][20]{};
    bool used[20][20];
    memset(used, true, sizeof(used));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &in);
            dist[i][j] = in;
        }
    }
    bool possible = true;
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == j || j == k || i == k) continue;
                if (dist[i][j] == dist[i][k] + dist[k][j]){
                    used[i][j] = false;
                }
                else if (dist[i][j] > dist[i][k] + dist[k][j]) possible = false;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (used[i][j]) ans += dist[i][j];
        }
    }
    printf("%d\n", possible ? ans / 2 : -1);
}