#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
using ll = long long;
const int SIZE = 1 << 20;
struct segTree{
    ll sum[SIZE];
    int start;
    segTree(int n){
        fill(sum, sum + SIZE, 0);
        for (start = 1; start < n; start <<= 1);
    }
    void update(int i, int val){
        i += start;
        sum[i] = val;
        while (i){
            i /= 2;
            sum[i] = sum[i * 2] + sum[i * 2 + 1];
        }
    }
    ll getSum(int l, int r){
        return getSum(l, r, 1, 0, start);
    }
    ll getSum(int l, int r, int node, int nl, int nr){
        if (nr <= l || r <= nl) return 0;
        if (l <= nl && nr <= r) return sum[node];
        int mid = (nl + nr) / 2;
        return getSum(l, r, node * 2, nl, mid) + getSum(l, r, node * 2 + 1, mid, nr);
    }
};
int main(){
    int N;
    scanf("%d", &N);
    vector<int> A, line;
    vector<p> B;
    for (int i = 0; i < N * 2; i++){
        int in;
        scanf("%d", &in);
        if (i < N) A.push_back(in);
        else B.push_back({in, i - N});
    }
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++){
        int val = A[i];
        auto iter = lower_bound(B.begin(), B.end(), p(val, 0));
        line.push_back(iter->second);
    }
    ll ans = 0;
    segTree st(N);
    for (int curr : line){
        ans += st.getSum(0, N - curr);
        st.update(N - curr - 1, 1);
    }
    printf("%lld", ans);
}