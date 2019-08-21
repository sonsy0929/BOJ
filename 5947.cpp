#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
using p = pair<int,int>;
int N, NQ, P, table[50000][50];
int main(){
    scanf("%d %d %d", &N, &NQ, &P);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < NQ; j++){
            scanf("%d", &table[i][j]);
        }
    }
    vector<p> query;
    for (int i = 0; i < P; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        query.push_back({a-1,b});
    }
    bool ret[50000];
    memset(ret, true, sizeof(ret));
    for (auto pCurr : query){
        int c = pCurr.first, a = pCurr.second;
        for (int i = 0; i < N; i++){
            ret[i] &= table[i][c] == a;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++){
        if (ret[i]) ans++;
    }
    printf("%d\n", ans);
}