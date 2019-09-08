#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using p = pair<int,int>;
const ll INF = 1e18;
vector<p> adj[100];
int N, S, E, M, income[100];
bool isConnect[100][100];
void floyd(){
    for (int k = 0; k < N; k++){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
               if (isConnect[i][k] && isConnect[k][j]) isConnect[i][j] = 1;
            }
        }
    }
}
int main(){
    scanf("%d %d %d %d", &N, &S, &E, &M);
    for (int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v,w});
        isConnect[u][v] = true;
    }
    for (int i = 0; i < N; i++){
        scanf("%d", &income[i]);
        isConnect[i][i] = true;
    }
    ll money[100];
    fill(money, money + 100, INF);
    money[S] = -income[S];
    bool GEE = false;
    floyd();
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            for (auto pNext : adj[j]){
                int next = pNext.first;
                int w = pNext.second;
                if (money[j] == INF) continue;
                if (money[next] > money[j] + w - income[next]){
                    money[next] = money[j] + w - income[next];
                    if (i == M - 1){
                        GEE |= isConnect[j][E];
                    }
                }
            }
        }
    }
    if (money[E] == INF) puts("gg");
    else{
        if (!GEE) printf("%lld\n", -money[E]);
        else puts("Gee");
    }
}