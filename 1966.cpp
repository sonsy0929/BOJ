#include <cstdio>
#include <deque>
using namespace std;
typedef pair<int, int> p;
int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        deque<p> dq;
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            int in;
            scanf("%d", &in);
            dq.push_back({in, i});
        }
        int ans = 1;
        bool possible = false;
        while (1){
            auto f = dq.front();
            int val = f.first;
            possible = true;
            for (int i = 1; i < dq.size(); i++){
                if (val < dq[i].first) {
                    dq.push_back(f);
                    dq.pop_front();
                    possible = false;
                    break;
                }
            }
            if (f.second == m && possible) break;
            if (possible) {
                ans++;
                dq.pop_front();
            }
        }
        printf("%d\n", ans);
    }
}