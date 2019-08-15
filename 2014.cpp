#include <cstdio>
#include <queue>
#include <climits>
#include <vector>
#include <functional>
using namespace std;
using ll = long long;
const int INF = INT_MAX;
int main(){
    int k, n;
    scanf("%d %d", &k, &n);
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> primes;
    for (int i = 0; i < k; i++){
        int in;
        scanf("%d", &in);
        primes.push_back(in);
        pq.push(in);
    }
    int prev = 0;
    for (int i = 0; i < n; i++){
        while (prev == pq.top()) pq.pop();
        int curr = pq.top();
        pq.pop();
        for (int prime : primes){
            ll val = 1LL * curr * prime;
            if (val >= INF) continue;
            pq.push(curr * prime);
        }
        prev = curr;
    }
    printf("%d\n", prev);
}