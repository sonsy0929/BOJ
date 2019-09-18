#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int, int>;
const int SIZE = 100'001;
int N;
int main(){
    scanf("%d", &N);
    vector<p> pv;
    for (int i = 0; i < N; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        pv.push_back({s, e});
    }
    sort(pv.begin(), pv.end(), [](const p &u, const p &v){
        if (u.second == v.second) return u.first < v.first;
        return u.second < v.second;
    });
    int ans = 1;
    auto prev = pv[0];
    for (int i = 1; i < N; i++){
        if (prev.second <= pv[i].first){
            ans++;
            prev = pv[i];
        }
    }
    printf("%d\n", ans);
}