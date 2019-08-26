#include <cstdio>
#include <cstring>
using namespace std;
const int SIZE = 1 << 22;
struct segTree{
    int sum[SIZE];
    int start;
    segTree(){
        start = 1 << 21;
        memset(sum, 0, sizeof(sum));
    }
    void update(int i, int val){
        i += start;
        sum[i] += val;
        while (i){
            i /= 2;
            sum[i] = sum[i * 2] + sum[i * 2 + 1];
        }
    }
    int kth(int node, int k){
        if (node >= start) return node - start;
        int piv = sum[node * 2];
        if (k <= piv) return kth(node * 2, k);
        else return kth(node * 2 + 1, k - piv);
    }
};
int main(){
    int N;
    scanf("%d", &N);
    segTree st;
    for (int i = 0; i < N; i++){
        int q, in;
        scanf("%d %d", &q, &in);
        if (q == 1){
            st.update(in - 1, 1);
        }
        if (q == 2){
            int val = st.kth(1, in);
            printf("%d\n", val + 1);
            st.update(val, -1);
        }
    }
}