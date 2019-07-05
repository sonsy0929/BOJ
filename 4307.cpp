#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int l, k;
        scanf("%d %d", &l, &k);
        vector<int> v;
        for (int i = 0; i < k; i++){
            int in;
            scanf("%d", &in);
            v.push_back(in);
        }
        int ans = 0, ans2 = 0;
        for (auto &it : v) {
            ans = max({ans, min(it, l - it)});
            ans2 = max({ans2, it, l - it});
        }
        printf("%d %d\n", ans, ans2);
    }
}