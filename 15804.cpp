#include <bits/stdc++.h>
using namespace std;
using p = pair<int,int>;
int N, M, S, T;
int main(){
    vector<p> bus;
    deque<p> station;
    scanf("%d %d",&N,&M);
    for (int i = 0; i < M; i++){
        scanf("%d %d",&S,&T);
        bus.push_back({S,T});
    }
    int i = 0;
    for (int t = 0; ;t++){
        while(!station.empty() && station.front().second <= t) station.pop_front();
        while((station.empty() || station.back().first < N) && bus[i].first <= t){
            if (station.empty()) station.push_back({1, t + bus[i].second});
            else station.push_back({station.back().first + 1, t + bus[i].second});
            i++;
            if (i == M){
                printf("%d\n", station.back().first);
                return 0;
            }
        }
    }
}