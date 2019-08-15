#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using p = pair<int,int>;
const int SIZE = 1 << 18;
struct segTree{
    ll sum[SIZE];
    int start;
    segTree(int n){
        memset(sum, 0, sizeof(sum));
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
    segTree st(N);
    vector<p> v;
    for (int i = 0; i < N; i++){
        int in;
        scanf("%d", &in);
        st.update(i, 1);
        v.push_back({in, i});
    }
    sort(v.begin(), v.end());
    ll prevTime = 0;
    ll ans[SIZE]{};
    for (auto pCurr : v){
        int t = pCurr.first, idx = pCurr.second;
        ll leftTime = st.getSum(0, idx + 1) * t;
        ll rightTime = st.getSum(idx + 1, N) * (t - 1);
        ans[idx] = leftTime + rightTime + prevTime;
        prevTime += t;
        st.update(idx, 0);
    }
    for (int i = 0; i < N; i++) printf("%lld\n", ans[i]);
}