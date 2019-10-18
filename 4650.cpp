#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
using tup = tuple<int,int,int>;
int uf[30];
int find(int n){
    if (uf[n] < 0) return n;
    return uf[n] = find(uf[n]); 
}
bool merge(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return false;
    uf[u] = v;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (1){
        int N;
        cin >> N;
        if (!N) break;
        fill(uf, uf + N, -1);
        vector<tup> edges;
        for (int i = 0; i < N - 1; i++){
            char src; int cnt;
            cin >> src >> cnt;
            for (int j = 0; j < cnt; j++){
                char dst; int w;
                cin >> dst >> w;
                edges.push_back({w, src-'A', dst-'A'});
            }
        }
        sort(edges.begin(), edges.end());
        int ans = 0, edgeCnt = N - 1;
        for (auto edge : edges){
            int w, u, v;
            tie(w, u, v) = edge;
            if (merge(u, v)){
                ans += w;
                if (--edgeCnt == 0) break;
            }
        }
        cout << ans << "\n";
    }
}