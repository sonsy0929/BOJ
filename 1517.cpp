#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
using ll = long long;
const int MAXN = 500'000;
const int SIZE = 1 << 20;    
int idx[MAXN];
struct segTree{
    ll sum[SIZE];
    int start;
    segTree(int N){
        memset(sum, 0, sizeof(sum));
        for (start = 1; start < N; start <<= 1);
    }
    void update(int i, int val){
        i += start;
        sum[i] = val;
        while(i){
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
        v.push_back({in, i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++){
        auto pCurr = v[i];
        idx[pCurr.second] = i;
    }
    ll ans = 0;
    for (int i = 0; i < N; i++){
        ans += st.getSum(idx[i], N);
        st.update(idx[i], 1);
    }
    printf("%lld\n", ans);
}