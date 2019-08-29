#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
const int SIZE = 1 << 18;
int N, K, v[SIZE];
struct segTree{
    int sum[SIZE];
    int start;
    segTree(){
        fill(sum, sum + SIZE, 0);
        start = SIZE / 2;
    }
    void update(int i, int val){
        i += start;
        while(i){
            sum[i] += val;
            i /= 2;
        }
    }
    int kth(int n, int k){
        if (n >= start) return n-start;
        int piv = sum[n*2];
        if (piv >= k) return kth(n*2, k);
        return kth(n*2+1, k-piv);
    }
};
int main(){
    scanf("%d %d", &N, &K);
    segTree st;
    int pos = (K + 1) / 2;
    ll ans = 0;
    for (int i = 0; i < N; i++){
        int in;
        scanf("%d", &in);
        v[i] = in;
        st.update(in, 1);
        if (i >= K-1){
            int ret = st.kth(1, pos);
            ans += ret;
            st.update(v[i-(K-1)], -1);
        }
    }
    printf("%lld", ans);
}