#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, mx;
multiset<int> st;
int main(){
    scanf("%d", &N);
    vector<int> crain(N, 0);
    for (int i = 0; i < N; i++) scanf("%d", &crain[i]);
    scanf("%d", &M);
    for (int i = 0; i < M; i++){
        int in;
        scanf("%d", &in);
        st.insert(-in);
        mx = max(mx, in);
    }
    sort(crain.begin(), crain.end());
    if (mx > crain.back()){
        puts("-1");
        return 0;
    }
    int ans = 0;
    for (; !st.empty(); ans++){
        for (int i = 0; i < N; i++){
            auto it = st.lower_bound(-crain[i]);
            if (it != st.end()) st.erase(it);
        }
    }
    printf("%d\n", ans);
}