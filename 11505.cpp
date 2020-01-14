#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr int SIZE = 1 << 21;
constexpr int MOD = 1e9+7;
int N, M, K;
struct segTree{
    int start;
    ll data[SIZE];
    segTree(){
        for (start = 1; start < N; start <<= 1);
        fill(data, data+SIZE, 1);
    }
    void update(int i, int k){
        i += start;
        data[i] = k;
        while (i/2){
            i/=2;
            data[i] = (data[i*2]*data[i*2+1])%MOD;
        }
    }
    ll getMul(int s, int e){
        return getMul(s, e, 1, 0, start);
    }
    ll getMul(int s, int e, int node, int ns, int ne){
        if (ne <= s || ns >= e) return 1;
        if (s <= ns && ne <= e) return data[node];
        int mid = (ns+ne)/2;
        return (getMul(s,e,node*2,ns,mid)*getMul(s,e,node*2+1,mid,ne))%MOD;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> N >> M >> K;
    segTree st;
    for (int i = 0; i < N; i++){
        int in;
        cin >> in;
        st.update(i, in);
    }
    for (int i = 0; i < M+K; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if (a == 1) st.update(b-1, c);
        if (a == 2) cout << st.getMul(b-1,c)%MOD << "\n";
    }
}