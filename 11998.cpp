#include <cstdio>
#include <queue>
#include <cmath>
#include <functional>
using namespace std;
using p = pair<int,int>;
const int INF = 1e9;
int X, Y, K, M, ans = INF;
function<p(int, int)> f[6] = {
    [](int a, int b) {return p(X, b);},
    [](int a, int b) {return p(a, Y);},
    [](int a, int b) {return p(a, 0);},
    [](int a, int b) {return p(0, b);},
    [](int a, int b) {
        if (a + b <= X) return p(a + b, 0);
        else return p(X, b - (X - a));
    },
    [](int a, int b) {
        if (a + b <= Y) return p(0, a + b);
        else return p(a - (Y - b), Y);
    }
};
bool isPossible(p state){
    int A = state.first;
    int B = state.second;
    if (A > X || B > Y || A < 0 || B < 0) return false;
    return true;
}
int bfs(){
    queue<p> q;
    bool visited[101][101]{};
    q.push({0, 0});
    visited[0][0] = true;
    for (int k = 0; !q.empty() && k <= K; k++){
        int qSize = q.size();
        for (int s = 0; s < qSize; s++){
            auto pCurr = q.front();
            q.pop();
            int A = pCurr.first;
            int B = pCurr.second;
            ans = min(ans, abs(M - (A + B)));
            for (int d = 0; d < 6; d++){
                p next = f[d](A, B);
                if (!isPossible(next) || visited[next.first][next.second]) continue;
                q.push(next);
                visited[next.first][next.second] = true;
            }
        }
    }
    return ans;
}
int main(){
    scanf("%d %d %d %d", &X, &Y, &K, &M);
    printf("%d\n", bfs());
}