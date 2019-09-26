#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int INF = 1e9;
int N;
set<int> ids;
map<int,int> contain;
vector<p> cows;
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        int x, n;
        scanf("%d %d", &x, &n);
        cows.push_back({x, n});
        ids.insert(n);
    }
    sort(cows.begin(), cows.end());
    int s = 0, e = 0, mn = INF;
    while (e < N){
        contain[cows[e].second]++;
        while (contain[cows[s].second] > 1){
            contain[cows[s].second]--;
            if (!contain[cows[s].second]){
                contain.erase(cows[s].second);
            }
            s++;
        }
        if (ids.size() == contain.size()){
            mn = min(mn, cows[e].first - cows[s].first);
        }
        e++;
    }
    printf("%d\n", mn);
}