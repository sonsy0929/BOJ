#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1 << 21;
struct segTree {
    int start;
    long long arr[SIZE], lazy[SIZE];
    segTree() {
        start = SIZE / 2;
        memset(arr, 0, sizeof(arr));
        memset(lazy, 0, sizeof(arr));
    }
    void construct() {
        for (int i = start - 1; i > 0; i--) {
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
        }
    }
    void input(int i, int val) {
        arr[i + start] = val;
    }
    void propagate(int node, int ns, int ne) {
        if (lazy[node] != 0) {
            if (node < start) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            arr[node] += lazy[node] * (ne - ns);
            lazy[node] = 0;
        }
    }
    void add(int s, int e, int k) {
        add(s, e, k, 1, 0, start);
    }
    void add(int s, int e, int k, int node, int ns, int ne) {
        propagate(node, ns, ne);
        if (e <= ns || ne <= s) return;
        if (s <= ns && ne <= e) {
            lazy[node] += k;
            propagate(node, ns, ne);
            return;
        }
        int mid = (ns + ne) / 2;
        add(s, e, k, node * 2, ns, mid);
        add(s, e, k, node * 2 + 1, mid, ne);
        arr[node] = arr[node * 2] + arr[node * 2 + 1];
    }
    long long sum(int s, int e) {
        return sum(s, e, 1, 0, start);
    }
    long long sum(int s, int e, int node, int ns, int ne) {
        propagate(node, ns, ne);
        if (e <= ns || ne <= s) return 0;
        if (s <= ns && ne <= e) return arr[node];
        int mid = (ns + ne) / 2;
        return sum(s, e, node * 2, ns, mid) + sum(s, e, node * 2 + 1, mid, ne);
    }
};
int main() {
    int N, M, K;
    long long in;
    scanf("%d %d %d", &N, &M, &K);
    segTree st;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &in);
        st.input(i, in);
    }
    st.construct();
    int Q = M + K;
    for (int i = 0; i < Q; i++) {
        int b, c;
        long long d;
        scanf("%d", &in);
        if (in == 1) {
            scanf("%d %d %lld", &b, &c, &d);
            st.add(b - 1, c, d);
        } else {
            scanf("%d %d", &b, &c);
            printf("%lld\n", st.sum(b - 1, c));
        }
    }
}