#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZE = 1 << 21;
struct segTree{
    long long arr[SIZE];
    int start;
    segTree(int N){
        for (start = 1; start < N; start *= 2);
        memset(arr, 0, sizeof(arr));
    }
    void update(int i, long long val){
        i += start;
        arr[i] = val;
        while (i > 1){
            i /= 2;
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
        }
    }
    long long getSum(int L, int R) { return getSum(L, R, 1, 0, start); }
    long long getSum(int L, int R, int node, int nL, int nR){
        if (R <= nL || nR <= L) return 0;
        if (L <= nL && nR <= R) return arr[node];
        int mid = (nL + nR) / 2;
        return getSum(L, R, node * 2, nL, mid) + getSum(L, R, node * 2 + 1, mid, nR);
    }
};
int main(){
    int N, M, K, q;
    scanf("%d %d %d", &N, &M, &K);
    segTree st(N);
    q = M + K;
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        st.update(i, val);
    }
    for (int i = 0; i < q; i++){
        int a, b;
        long long c;
        scanf("%d %d %lld", &a, &b, &c);
        if (a == 1){
            st.update(b - 1, c);
        }
        if (a == 2){
            printf("%lld\n", st.getSum(b - 1, c));
        }
    }
}