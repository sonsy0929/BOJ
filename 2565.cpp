#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
int V[1000], dp[1000], N;
int main(){
    int from, to;
    vector<p> rope;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d %d", &from, &to);
        rope.push_back({from, to});
    }
    sort(rope.begin(), rope.end());
    for (int i = 0; i < N; i++) V[i] = rope[i].second;
    for (int i = 0; i < N; i++){
        if (!dp[i]) dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (V[i] > V[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    printf("%d\n", N - *max_element(dp, dp + N));
}