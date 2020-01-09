/*
정렬, parametric search
11번의 시도 끝에 맞은 문제..
파라메트릭 서치를 이용했기 때문에 답의 범위를 설정해야 했다.
그런데 hi를 답으로 설정해놓고 lo를 1로 설정해서 절대 hi = 1 즉, 1이 답으로 나오지 못하게 설계를 하였다.
답이 나올 수 있는 범위는 1부터인데..
그래서 11번이나 틀렸었고, 틀에 갇힌 사고 방식으로 계속 틀렸었던 것 같다..
문제의 형식은 well-known한 파라메트릭 서치인데...
아 그리고 이 문제의 경우 단순히 우선순위 큐 만으로도 풀 수 있다고 한다.
이 방법은 다시 한번 생각해보고 구현을 해보아야겠다.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using ll = long long;
using p = pair<ll,ll>;
const int SIZE = 200'000;
const ll INF = 1e12;
int N, M, K;
p beer[SIZE];
bool isPossible(ll mid){
    int sum = 0, cnt = 0;
    for (int i = K-1; i >= 0; i--){
        if (beer[i].second <= mid){
            sum += beer[i].first;
            cnt++;
        }
        if (cnt == N) break;
    }
    return sum >= M && cnt == N;
}
int main(){
    scanf("%d %d %d", &N, &M, &K);
    int v, c;
    for (int i = 0; i < K; i++){
        scanf("%d %d", &v, &c);
        beer[i] = {v,c};
    }
    sort(beer, beer+K);
    ll lo = 0, hi = INF;
    while (lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        if (isPossible(mid)) hi = mid;
        else lo = mid;
    }
    printf("%lld", hi != INF ? hi : -1);
}