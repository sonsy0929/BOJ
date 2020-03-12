/*
�ð����⵵ : O(W^2)

���� ���̷���, ���ʰ� �����ʿ� ���̷��� ��ġ���� ū ���� �־�� �Ѵ�.
�� ��������, ����(L)�� ������(R)�� �ִ� ���̸� Ȯ���ϰ�
max(0, min(L, R) - '������ ����')�� �����ָ� �ȴ�.
*/
#include <bits/stdc++.h>
using namespace std;
int H, W;
int main() {
    scanf("%d %d", &H, &W);
    vector<int> B(W, 0);
    for (int i = 0; i < W; i++) {
        scanf("%d", &B[i]);
    }
    int ans = 0;
    for (int i = 1; i < W; i++) {
        int L = 0, R = 0;
        for (int l = 0; l < i; l++) L = max(L, B[l]);
        for (int r = W - 1; r > i; r--) R = max(R, B[r]);
        ans += max(0, min(L, R) - B[i]);
    }
    printf("%d", ans);
}