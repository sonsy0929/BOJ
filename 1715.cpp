#include <cstdio>
#include <queue>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++){
        int val;
        scanf("%d", &val);
        pq.push(val);
    }
    int ans = 0;
    while (pq.size() != 1){
        int u = pq.top();
        pq.pop();
        int v = pq.top();
        pq.pop();
        pq.push(u + v);
        ans += u + v;
    }
    printf("%d\n", ans);
}