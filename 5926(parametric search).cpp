#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int SIZE = 50000;
int N;
vector<int> IDs;
using p = pair<int,int>;
vector<p> cows;
bool f(int m){
    int curr = 0, cnt = 0;
    int contain[SIZE]{};
    for (int i = 0; i < N; i++){
        if (!contain[cows[i].second]) cnt++;
        contain[cows[i].second]++;
        while (cows[i].first - cows[curr].first > m){
            contain[cows[curr].second]--;
            if (!contain[cows[curr].second]) cnt--;
            curr++;
        }
        if (cnt == IDs.size()) return true;
    }
    return false;
}
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        int x, n;
        scanf("%d %d", &x, &n);
        cows.push_back({x,n});
        IDs.push_back(n);
    }
    sort(cows.begin(), cows.end());
    sort(IDs.begin(), IDs.end());
    IDs.erase(unique(IDs.begin(), IDs.end()), IDs.end());
    for (auto &pCurr : cows){
        int n = pCurr.second;
        int idx = lower_bound(IDs.begin(), IDs.end(), n) - IDs.begin();
        pCurr.second = idx;
    }
    int lo = 0, hi = 1e9;
    while (lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if (f(mid)) hi = mid;
        else lo = mid;
    }
    printf("%d\n", hi);
}