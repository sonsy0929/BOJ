#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using p = pair<int,int>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<p> condos(N);
    for (int i = 0; i < N; i++){
        cin >> condos[i].first >> condos[i].second;
    }
    sort(condos.begin(), condos.end());
    int ans = 0, minCost = 1e9;
    for (int i = 0; i < N; i++){
        int cost = condos[i].second;
        if (minCost > cost){
            minCost = cost;
            ans++;
        }
    }
    cout << ans << "\n";
}