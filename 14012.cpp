/*
(pay, get)���� �Է��� �޾Ƽ� �̸� �����ϸ� ���� Ǯ���� ����
���� pay ������ ��ȸ�ϸ鼭 �ҵ��� �߻��ϴ��� Ȯ���ϰ� �ҵ��� ����� ���ϴ� ����
�� ������ �� int ������ �Ѵ� �Ϳ� ����! �� ����! (1e5 * 1e6�̹Ƿ� overflow)
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