#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
const int SIZE = 300'000;
int uf[SIZE];
int find(int n){
    if (uf[n] < 0) return n;
    return uf[n] = find(uf[n]);
}
void merge(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return;
    uf[u] = v;
}
int main(){
    int N, u, v;
    scanf("%d", &N);
    memset(uf, -1, sizeof(uf));
    for (int i = 0; i < N - 2; i++){
        scanf("%d %d", &u, &v);
        u--, v--;
        merge(u, v);
    }
    vector<int> ans;
    for (int i = 0; i < N; i++){
        if (uf[i] < 0) ans.push_back(i+1);
    }
    printf("%d %d\n", ans[0], ans[1]);
}