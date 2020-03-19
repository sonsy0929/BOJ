/*
�ð����⵵ : O(N!)

N = 4���

1 -> 2 -> 3 -> 4 -> 1
1 -> 3 -> 2 -> 4 -> 1
...
2 -> 1 -> 3 -> 4 -> 2
2 -> 3 -> 1 -> 4 -> 2
...
3 -> 1 -> 2 -> 4 -> 3
...
4 -> 1 -> 2 -> 3 -> 4
...

�� ���� 4!�� TSP ��ΰ� ������ �ǰ�, �� �߿��� �ּҺ���� ���ϸ� �ȴ�.
�Ǽ��� �κ����δ�, '���� i���� ���� j�� �� �� ���� ��쵵 ������ �̷� ��� W[i][j]=0�̶�� ����.' 
�� ������ ����� ���� ���ؼ�, �� �� ���� TSP ��θ� �������� ���ߴ�.
*/

#include <bits/stdc++.h>
using namespace std;
int N, W[11][11];
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &W[i][j]);
        }
    }
    vector<int> permu;
    for (int i = 1; i <= N; i++) permu.push_back(i);
    int ans = 1e9;
    do {
        permu.push_back(permu[0]);
        int sum = 0, u, v;
        int sz = permu.size();
        bool possible = true;
        for (int i = 0; i < sz - 1; i++) {
            u = permu[i], v = permu[i + 1];
            sum += W[u][v];
            possible &= W[u][v] != 0;
        }
        permu.pop_back();
        if (!possible) continue;
        ans = min(ans, sum);
    } while (next_permutation(permu.begin(), permu.end()));
    printf("%d", ans);
}