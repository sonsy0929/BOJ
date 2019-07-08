#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<int, int> p;
int n, k;
p in[1002];
vector<int> adj[1002];
int getDist(p u, p v){
    return sqrt(pow(u.first - v.first, 2) + pow(u.second - v.second , 2));   
}
int getOil(p u, p v){
    int ret = getDist(u, v);
    return ret / 10;
}
void makeConnect(){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j <= n + 1; j++){
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
}
bool isPossible(int param){
    queue<int> q; 
    bool visited[1002]{};
    q.push(0);
    visited[0] = true;
    int cnt = 0;
    for (; !q.empty(); cnt++){
        int qSize = q.size();
        for (int s = 0; s < qSize; s++){
            int curr = q.front();
            q.pop();
            if (curr == n + 1) return k + 1 >= cnt;
            for (int next : adj[curr]){
                int oil = getOil(in[curr], in[next]);
                if (visited[next] || oil >= param) continue;
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return false;
}
int main(){
    scanf("%d %d", &n, &k);
    in[0] = {0, 0};
    in[n + 1] = {10000, 10000};
    for (int i = 1; i <= n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        in[i] = {x, y};
    }
    makeConnect();
    int lo = 0, hi = 15000;
    while (lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if (isPossible(mid)) hi = mid;
        else lo = mid;
    }
    printf("%d\n", hi);
}