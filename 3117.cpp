#include <cstdio>
#include <vector>
using namespace std;
const int SIZE = 100'001;
const int H = 31;
int D[SIZE][H], playList[SIZE];
int main(){
    int N, K, M;
    scanf("%d %d %d", &N, &K, &M);
    for (int i = 1; i <= N; i++) scanf("%d", playList+i);
    for (int i = 1; i <= K; i++) scanf("%d", &D[i][0]);
    for (int i = 1; i < H; i++){
        for (int j = 1; j <= K; j++){
            D[j][i] = D[D[j][i-1]][i-1];
        }
    }
    vector<int> ans;
    for (int i = 1; i <= N; i++){
        int k = playList[i], cnt = M-1;
        for (int j = 0; cnt; j++){
            if (cnt % 2) k = D[k][j];
            cnt /= 2;
        }
        ans.push_back(k);
    }
    for (int curr : ans) printf("%d ", curr);
}