/*
����, parametric search
11���� �õ� ���� ���� ����..
�Ķ��Ʈ�� ��ġ�� �̿��߱� ������ ���� ������ �����ؾ� �ߴ�.
�׷��� hi�� ������ �����س��� lo�� 1�� �����ؼ� ���� hi = 1 ��, 1�� ������ ������ ���ϰ� ���踦 �Ͽ���.
���� ���� �� �ִ� ������ 1�����ε�..
�׷��� 11���̳� Ʋ�Ⱦ���, Ʋ�� ���� ��� ������� ��� Ʋ�Ⱦ��� �� ����..
������ ������ well-known�� �Ķ��Ʈ�� ��ġ�ε�...
�� �׸��� �� ������ ��� �ܼ��� �켱���� ť �����ε� Ǯ �� �ִٰ� �Ѵ�.
�� ����� �ٽ� �ѹ� �����غ��� ������ �غ��ƾ߰ڴ�.
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