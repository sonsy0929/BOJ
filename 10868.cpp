#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZE = 1 << 18;
const int INF = 0x3f3f3f3f;
int N, M;
struct segTree{
    int arr[SIZE];
    int start;
    segTree(int N){
        for (start = 1; start < N; start <<= 1);
        memset(arr, INF, sizeof(arr));
    }
    void update(int i, int val){
        i += start;
        arr[i] = val;
        while (i){
            i /= 2;
            arr[i] = min(arr[i * 2], arr[i * 2 + 1]);
        }
    }
    int getMin(int l, int r) { return getMin(l, r, 1, 0, start);}
    int getMin(int l, int r, int node, int nl, int nr){
        if (nr <= l || r <= nl) return INF;
        if (l <= nl && nr <= r) return arr[node];
        int mid = (nl + nr) / 2;
        return min(getMin(l, r, node * 2, nl, mid), getMin(l, r, node * 2 + 1, mid, nr));
    }
};
int main(){
    scanf("%d %d", &N, &M);
    segTree st(N);
    for (int i = 0; i < N; i++){
        int in;
        scanf("%d", &in);
        st.update(i, in);
    }
    for (int i = 0; i < M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", st.getMin(a - 1, b));
    }
}
