#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int SIZE = 1 << 18;
const int INF = 1e9 + 10;
int N;
vector<int> histogram;
struct segTree{
    int v[SIZE];
    int start;
    segTree(int n){
        fill(v, v + SIZE, N);
        for (start = 1; start < n; start <<= 1);
    }
    void update(int i, int val){
        i += start;
        v[i] = val;
        while (i){
            i /= 2;
            int left = v[i*2];
            int right = v[i*2+1];
            if (histogram[left] > histogram[right]) v[i] = right;
            else if (histogram[left] == histogram[right]){
                if (left > right) v[i] = right;
                else v[i] = left;
            }
            else v[i] = left;
        }
    }
    int getMin(int l, int r){
        return getMin(l, r, 1, 0, start);
    }
    int getMin(int l, int r, int node, int nl, int nr){
        if (nr <= l || r <= nl) return N;
        if (l <= nl && nr <= r) return v[node];
        int mid = (nl + nr) / 2;
        int left = getMin(l, r, node * 2, nl, mid);
        int right = getMin(l, r, node * 2 + 1, mid, nr);
        if (histogram[left] > histogram[right]) return right;
        else if (histogram[left] == histogram[right]){
            if (left > right) return right;
            else return left;
        }
        return left;
    }
};
ll f(int l, int r, segTree &st){
    if (l + 1 == r) return histogram[l];
    int idx = st.getMin(l, r);
    ll ret = 1LL * (r - l) * histogram[idx];
    if (l < idx) ret = max(ret, f(l, idx, st));
    if (idx < r - 1) ret = max(ret, f(idx + 1, r, st));
    return ret;
}
int main(){
    while (1){
        histogram.clear();
        scanf("%d", &N);
        if (!N) break;
        segTree st(N);
        for (int i = 0; i < N; i++){
            int in;
            scanf("%d", &in);
            histogram.push_back(in);
        }
        histogram.push_back(INF);
        for (int i = 0; i < N; i++){
            st.update(i, i);
        }
        ll ans = f(0, N, st);
        printf("%lld\n", ans);
    }
}