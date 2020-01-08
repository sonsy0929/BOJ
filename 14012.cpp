/*
(pay, get)으로 입력을 받아서 이를 정렬하면 쉽게 풀리는 문제
적은 pay 순으로 순회하면서 소득이 발생하는지 확인하고 소득이 생기면 더하는 구조
다 더했을 때 int 범위를 넘는 것에 조심! 또 조심! (1e5 * 1e6이므로 overflow)
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
using ll = long long;
const int SIZE = 1e5;
p challenge[SIZE];
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &challenge[i].first);
    for (int i = 0; i < N; i++) scanf("%d", &challenge[i].second);
    sort(challenge, challenge + N);
    ll ans = M;
    for (auto pCurr : challenge){
        int pay = pCurr.first;
        int get = pCurr.second;
        if (ans >= pay && get - pay > 0) ans += get - pay;
    }
    printf("%lld", ans);
}