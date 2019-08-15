#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
const int SIZE = 32'000;
int in[SIZE];
vector<int> adj[SIZE];
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        in[b]++;
        adj[a].push_back(b);
    }
    for (int i = 0; i < N; i++){
        if (!in[i]) pq.push(i);
    }
    vector<int> res;
    for (int i = 0; i < N; i++){
        int curr = pq.top();
        pq.pop();
        res.push_back(curr);
        for (int next : adj[curr]){
            if (--in[next] == 0) pq.push(next);
        }
    }
    for (int curr : res) printf("%d ", curr + 1);
}