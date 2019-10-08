#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int SIZE = 1 << 18;
const int INF = 0x3fffffff;
struct segTree{
    p ST[SIZE];
    int start;
    segTree(int N){
        for (start = 1; start < N; start <<= 1);
        for (int i = 0; i < SIZE; i++){
            ST[i].first = INF;
            ST[i].second = INF;
        }
    }
    void update(int i, int val){
        i += start;
        ST[i].first = val;
        ST[i].second = i - start;
        while (i){
            i /= 2;
            ST[i] = min(ST[i*2], ST[i*2+1]);
        }
    }
    p getMin(int s, int e){
        return getMin(s, e, 1, 0, start);
    }
    p getMin(int s, int e, int n, int ns, int ne){
        if (ne <= s || e <= ns) return p(INF,INF);
        if (s <= ns && ne <= e) return ST[n];
        int mid = (ns + ne) / 2;
        return min(getMin(s, e, n*2, ns, mid), getMin(s, e, n*2+1, mid, ne));
    }
};
int main(){
    int n, m;
    scanf("%d", &n);
    segTree st(n);
    for (int i = 0; i < n; i++){
        int in;
        scanf("%d", &in);
        st.update(i, in);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        int q;
        scanf("%d", &q);
        if (q == 1){
            int a, b;
            scanf("%d %d", &a, &b);
            st.update(a-1, b);
        }
        else{
            auto ret = st.getMin(0, n);
            printf("%d\n", ret.second+1);
        }
    }
}