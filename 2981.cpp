/*
��� ���� �� ��� ������ ������ ���ϸ�
a[i] = MQ[i] + d �÷� ǥ���� �� �� �ִ�.
a[n] = MQ[n] + d
a[n+1] = MQ[n+1] + d�̹Ƿ�
a[n+1] - a[n] = M(Q[n+1] - Q[n]) ���� ���´�.
��, a[n+1] - a[n] = k�� �ϸ�, M�� k�� ������ ���� ���� ����� ���� �� �� �ִ�.
�̸� ����, ������ ������ �ִ������� ����
�� �ִ������� ����� ���ϸ� M�� ��� ã�� �� �ִ�!
*/
#include <bits/stdc++.h>
using namespace std;
int N, A[100];
int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", A + i);
    sort(A, A + N);
    int GCD = A[1] - A[0];
    for (int i = 2; i < N; i++) {
        GCD = gcd(GCD, A[i] - A[i - 1]);
    }
    vector<int> ans;
    for (int i = 2; i * i <= GCD; i++) {
        if (GCD % i == 0) {
            ans.push_back(i);
            if (i * i != GCD) ans.push_back(GCD / i);
        }
    }
    ans.push_back(GCD);
    sort(ans.begin(), ans.end());
    for (int curr : ans) printf("%d ", curr);
}