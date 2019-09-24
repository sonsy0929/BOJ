#include <cstdio>
#include <cstring>
using namespace std;
const int SEGSIZE = 1 << 20;
struct segTree{
    int st[SEGSIZE];
    int start;
    segTree(int n){
        memset(st, 0, sizeof(st));
        for (start = 1; start < n; start <<= 1);
    }
    void update(int i, int k){
        i += start;
        while (i){
            st[i] += k;
            i /= 2;
        }
    }
    int kth(int i, int k){
        if (i >= start) return i-start+1;
        int piv = st[i*2];
        if (piv >= k) return kth(i*2, k);
        else return kth(i*2+1, k-piv);
    }
};
int main(){
    int N, Q;
    scanf("%d", &N);
    segTree st(N);
    for (int i = 0; i < N; i++){
        int in;
        scanf("%d", &in);
        st.update(i, in);
    }
    scanf("%d", &Q);
    while(Q--){
        int q, i, a;
        scanf("%d %d", &q, &i);
        if (q == 1){
            scanf("%d", &a);
            st.update(i-1, a);
        }
        else printf("%d\n", st.kth(1, i));
    }
}