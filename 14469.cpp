#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
int main(){
    int N;
    scanf("%d", &N);
    vector<p> cows;
    for (int i = 0; i < N; i++){
        int s, t;
        scanf("%d %d", &s, &t);
        cows.push_back({s, t});
    }
    sort(cows.begin(), cows.end());
    int ans = 0;
    for (auto curr : cows){
        int s = curr.first;
        int t = curr.second;
        ans = max(s, ans) + t;
    }
    printf("%d\n", ans);
}