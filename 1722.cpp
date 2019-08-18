#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
int N, Q;
ll K, dp[21];
bool used[21];
vector<int> ans;
void init(){
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i < 21; i++){
        dp[i] = dp[i - 1] * i;
    }
}
void f(int pos, ll k){
    if (!pos) return;
    for (int i = 1; i <= N; i++){
        if (used[i]) continue;
        if (k <= dp[pos-1]){
            used[i] = true;
            ans.push_back(i);
            f(pos-1, k);
            break;
        }
        k -= dp[pos-1];
    }
}
ll kth(int pos, vector<int> &in){
    if (!pos) return 1;
    ll cnt = 0;
    for (int i = 1; i <= N; i++){
        if (used[i]) continue;
        if (in[N - pos] == i){
            used[i] = true;
            return kth(pos-1, in) + cnt;
        }
        cnt += dp[pos-1];
    }
}
int main(){
    init();
    scanf("%d %d", &N, &Q);
    if (Q == 1){
        scanf("%lld", &K);
        f(N, K);
        for (int curr : ans) printf("%d ", curr);
    }
    else {
        vector<int> perm;
        for (int i = 0; i < N; i++){
            int in;
            scanf("%d", &in);
            perm.push_back(in);
        }
        printf("%lld", kth(N, perm));
    }
}