#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int SIZE = 1 << 18;
struct segTree{
    int sum[SIZE];
    int start;
    segTree(int N){
        memset(sum, 0, sizeof(sum));
        for (start = 1; start < N; start <<= 1);
    }
    void update(int i, int val){
        i += start;
        sum[i] = val;
        while (i){
            i /= 2;
            sum[i] = sum[i*2] + sum[i*2 + 1];
        }
    }
    int kth(int pos, int k){
        if (pos >= start) return pos - start;
        int piv = sum[pos * 2];
        if (k <= piv) return kth(pos * 2, k);
        return kth(pos * 2 + 1, k - piv);
    }
    int getSum(int l, int r){
        return getSum(l, r, 1, 0, start);
    }
    int getSum(int l, int r, int node, int nl, int nr){
        if (nr <= l || r <= nl) return 0;
        if (l <= nl && nr <= r) return sum[node];
        int mid = (nl + nr) / 2;
        return getSum(l, r, node * 2, nl, mid) + getSum(l, r, node * 2 + 1, mid, nr);
    }
};
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> ans;
    segTree st(N);
    for (int i = 0; i < N; i++) st.update(i, 1);
    ans.push_back(M);
    int mod = N - 1;
    st.update(M - 1, 0);
    for (int i = 2; i < N + 1; i++){
        int curr = st.getSum(0, ans.back());
        int K = (curr + M) % mod;
        if (!K) K = mod;
        int sIdx = st.kth(1, K);
        ans.push_back(sIdx + 1);
        st.update(sIdx, 0);
        mod--;
    }
    printf("<%d", ans[0]);
    for (int i = 1; i < ans.size(); i++){
        printf(", %d", ans[i]);
    }
    printf(">");
}