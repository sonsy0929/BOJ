#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
int main(){
    int N;
    scanf("%d", &N);
    vector<p> v;
    for (int i = 0; i < N; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back({y,x});
    }
    sort(v.begin(), v.end());
    int l = 0, r = v.size() - 1, ans = 0;
    while (l < r){
        int &lx = v[l].second;
        int &rx = v[r].second;
        int mnCnt = min(lx, rx);
        lx -= mnCnt, rx -= mnCnt;
        ans = max(ans, v[l].first + v[r].first);
        if (!lx) l++;
        if (!rx) r--;
    }
    ans = max(ans, v[l].first + v[r].first);
    printf("%d\n", ans);
}