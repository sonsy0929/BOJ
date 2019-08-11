#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
using p = pair<int, int>;
const int INF = 1e9 + 1;
int N, L;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> N >> L;
    priority_queue<p, vector<p>, greater<p>> pq;
    for (int i = 0; i < N; i++){
        int val;
        cin >> val;
        while (!pq.empty() && pq.top().second <= i - L) pq.pop(); 
        pq.push({val, i});
        cout << pq.top().first << ' ';
    }
}