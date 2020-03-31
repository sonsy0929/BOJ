/*
��ũ������ �����ζ��, ���� ū �����ϴ� ���� '9876543210' ���� �ڸ��� ����̴�.
�̸� ����, k = 1 ~ 10���� 10�� �߿� �ߺ����� k���� �̾� �����ϴ� ������ Ȯ���ϸ� �ȴ�.
�� ��, '9876543210'�� int ������ �Ѿ�ٴ� �Ϳ� ���Ǹ� �ؾ� �Ѵ�. 
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
set<ll> used;
vector<ll> decreaseNums;
void comb(int cnt, ll num) {
    if (cnt > 10) return;
    for (int i = 0; i < 10; i++) {
        if (num && num % 10 <= i) continue;
        if (!used.count(num * 10 + i)) {
            used.insert(num * 10 + i);
            decreaseNums.push_back(num * 10 + i);
            comb(cnt + 1, num * 10 + i);
        }
    }
}
int main() {
    scanf("%d", &N);
    comb(0, 0LL);
    sort(decreaseNums.begin(), decreaseNums.end());
    if (decreaseNums.size() <= N)
        puts("-1");
    else
        printf("%lld", decreaseNums[N]);
}