#include <cstdio>
#include <map>
#include <set>
using namespace std;
int main(){
    int u, v, num = 1;
    map<int, int> in;
    set<int> st;
    int edgeCnt = 0;
    while (scanf("%d %d", &u, &v)){
        if (u == -1 && v == -1) break;
        if (!u && !v){
            bool possible = true;
            for (auto pCurr : in){
                int val = pCurr.second;
                if (val > 1) {
                    possible = false;
                    break;
                }
            }
            int rootCnt = 0;
            for (int curr : st){
                if (!in[curr]) rootCnt++;
            }
            int SIZE = st.size();
            if (SIZE && rootCnt != 1) possible = false;
            if (SIZE && SIZE != edgeCnt + 1) possible = false;
            if (possible) printf("Case %d is a tree.\n", num++);
            else printf("Case %d is not a tree.\n", num++);
            in.clear(); st.clear();
            edgeCnt = 0;
            continue;
        }
        in[v]++;
        st.insert(u), st.insert(v);
        edgeCnt++;
    }
}