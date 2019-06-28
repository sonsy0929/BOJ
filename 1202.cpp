/*
삼성SDS 입과테스트 우주전쟁? 이랑 비슷한 문제 같다
우선순위 큐를 활용하는 대표적인 문제
가치가 큰 보석을 무게 조건을 충족하는 가방에 넣어야 이득
'보석의 무게 <=가방에 담을 수 있는 최대무게'를 만족하는 보석 중 가치가 가장 큰 것
보석과 가방의 정보들을 무게 순으로 정렬해서, 가방의 정보가 나올 때 그 중에서 보석의 가치가 가장 큰 것을 선택해야 한다.
[ ~ 가방에 담을 수 있는 최대 무게]을 만족하는 보석 중 최대 가치를 가진 보석을 구하려면
보석의 가치를 우선순위큐(최대힙)에 push해서 위와 같은 구조를 유지해야 한다.
*/
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> p;
const int BAG = 1'000'001;
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<p> info;
    for (int i = 0; i < n + k; i++){
        int u, v;
        if (i < n) {
            scanf("%d %d", &u, &v);
            info.push_back({u, v});
        }
        else {
            scanf("%d", &u);
            info.push_back({u, BAG});
        }
    }
    sort(info.begin(), info.end());
    priority_queue<int> pq;
    long long ans = 0;
    for (auto it : info){
        if (it.second != BAG) pq.push(it.second);
        else {
            if (!pq.empty()) {
                ans += pq.top();
                pq.pop();
            }
        }
    }
    printf("%lld\n", ans);
}