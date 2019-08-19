#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int N, M;
vector<int> time;
bool isPosslble(ll m){
    ll cnt = 0;
    for (int i = 0; i < time.size(); i++){
        cnt += m / time[i];
    }
    return cnt >= M;
}
int main(){
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++){
        int in;
        scanf("%d", &in);
        time.push_back(in);
    }
    sort(time.begin(), time.end());
    ll lo = 0, hi = 1e18;
    while (lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        if (isPosslble(mid)) hi = mid;
        else lo = mid;
    }
    printf("%lld\n", hi);
}