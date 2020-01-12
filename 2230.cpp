#include <cstdio>
#include <set>
using namespace std;
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    set<int> st;
    for (int i = 0; i < n; i++){
        int in;
        scanf("%d", &in);
        st.insert(in);
    }
    int ans = 2e9;
    for (int i : st){
        auto it = st.lower_bound(i+m);
        if (it != st.end()) ans = min(ans, *it-i);
    }
    printf("%d\n", ans);
}