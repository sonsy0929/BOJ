#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
constexpr int MAXSIZE = 510;
vector<int> friendGraph[MAXSIZE];
int bfs(){
    int ret = 0;
    queue<int> q;
    bool visited[MAXSIZE]{};
    q.push(1);
    visited[1] = true;
    for (int k = 0; k < 2; k++){
        int qSize = q.size();
        for (int s = 0; s < qSize; s++){
            int front = q.front();
            q.pop();
            for (int next : friendGraph[front]){
                if (visited[next]) continue;
                ret++;
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return ret;
}
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        friendGraph[u].push_back(v);
        friendGraph[v].push_back(u);
    }
    printf("%d\n", bfs());
}