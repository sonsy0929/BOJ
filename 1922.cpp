#include <cstdio>
#include <vector>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;
using tup = tuple<int, int, int>;
int uf[1001];
int find(int k){
    if (uf[k] < 0) return k;
    return uf[k] = find(uf[k]);
}
bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    uf[a] = b;
    return true;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<tup> edge;
    memset(uf, -1, sizeof(uf));
    for (int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end());
    int ans = 0, edgeCnt = 0;
    for (auto tCurr : edge){
        int c, a, b;
        tie(c, a, b) = tCurr;
        if (merge(a, b)) {
            ans += c;
            if (++edgeCnt == n - 1) break;
        }
    }
    printf("%d\n", ans);
}