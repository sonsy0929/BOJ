#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
using p = pair<int, int>;
const int SIZE = 1 << 20;
int N, idx[500'000];
struct segTree{
    int S;
    int arr[SIZE];
    segTree(int N) : S(1) {
        memset(arr, 0, sizeof(arr));
        for (; S < N; S *= 2); 
    }
    void update(int i, int val){
        i += S;
        arr[i] = val;
        while (i){
            i /= 2;
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
        }
    }
    int getSum(int s, int e) {return getSum(s, e, 1, 0, S);}
    int getSum(int s, int e, int node, int ns, int ne){
        if (ne <= s || ns >= e) return 0;
        if (s <= ns && ne <= e) return arr[node];
        int mid = (ns + ne) / 2;
        return getSum(s, e, node * 2, ns, mid)
                + getSum(s, e, node * 2 + 1, mid, ne);
    }
};
int main(){
    scanf("%d", &N);
    vector<p> runner;
    for (int i = 0; i < N; i++) {
        int in;
        scanf("%d", &in);
        runner.push_back({in, i});
    }
    sort(runner.begin(), runner.end());
    for (int i = 0; i < N; i++){
        auto p = runner[i];
        idx[p.second] = i;
    }
    segTree st(N);
    for (int i = 0; i < N; i++){
        printf("%d\n", i + 1 - st.getSum(0, idx[i]));
        st.update(idx[i] , 1);
    }
}