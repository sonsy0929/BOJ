/*
�ð����⵵ : O(M log*N) => ���� O(M)

�ܼ��� dfs�� Ǯ��, �־��� ��쿡 skewed�� �׷����� ������ 
100'000 + 99'999 + ... + 2 + 1 �̷� ������ ������ �� �� �ֱ� ������
union-find�� path-compression(��� ����)�� ���־���.
����(����)�� ��ȣ�� 1���� N������ ��ȣ�̹Ƿ�,
������ ������� �ʴ´ٴ� ���� �� �� �ִ�.
����, ��ǥ��(root)�� ������ ���� ������ �����ϴ� ������� ������ �ϸ�,
�ܼ��� ������� ��Ǹ����� root���� �� �� �ְ�,
������ �� ���� ������ �� �ִ�.
����, '����'�� �Ͼ �� ������ ���� ���� ������ ���� ������ ����ϴµ�,
�� �� ��Ұ��踦 |a| < |b|�� ���������ν� ���̽� �з��� ���� �ʴ� ����� �̿��ߴ�.
*/

#include <bits/stdc++.h>
using namespace std;
int N, M, uf[100'001];
int find(int n) {
    if (uf[n] < 0) return n;
    return uf[n] = find(uf[n]);
}
void merge(int o, int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (uf[a] > uf[b]) swap(a, b);
    uf[a] = uf[a] + uf[b] * o;
    uf[b] = a;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        int in;
        scanf("%d", &in);
        uf[i] = -in;
    }
    for (int i = 1; i <= M; i++) {
        int o, p, q;
        scanf("%d %d %d", &o, &p, &q);
        if (o == 1) {
            merge(1, p, q);
        } else {
            merge(-1, p, q);
        }
    }
    int ans = 0;
    vector<int> people;
    for (int i = 1; i <= N; i++) {
        if (uf[i] < 0) {
            ans++;
            people.push_back(-uf[i]);
        }
    }
    sort(people.begin(), people.end());
    printf("%d\n", ans);
    for (int curr : people) printf("%d ", curr);
}