/*
�ð����⵵ : O(N)

�ּҰ��� ��������, ���Ϳ��� �Ÿ��� ���� ��ġ���� ���ʴ�� ���� ���ƾ� �Ѵ�.
��, �Ÿ��� 1�� ��ġ�� ���� ���� �ְ�, �׷��� ���� �� ���ƾ� �Ѵٸ� �Ÿ��� 2�� ��ġ��
���� ����, ���� ������� �Ÿ��� 1�� �÷����鼭 ���� ���ƾ� �Ѵ�.

�Ÿ��� 1�� ��ġ�� ���Ϳ� ������ ���̰�, �Ÿ��� 2�� ��ġ�� �Ÿ��� 1�� ��ġ�� ������ ���̴�.
��, ��� ������ ��ġ�� ť�� �ְ� BFS�� �����鼭 ���� ��ġ�ϸ� �ȴٴ� ���� �� �� �ִ�.
*/

#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;
set<int> used;
int n, k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    queue<p> q;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        q.push({0, in});
        used.insert(in);
    }
    long long ans = 0;
    int cnt = 0;
    int addVal[2] = {1, -1};
    while (!q.empty()) {
        auto [d, f] = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            int nf = f + addVal[i];
            if (!used.count(nf)) {
                used.insert(nf);
                q.push({d + 1, nf});
                ans += d + 1;
                if (++cnt >= k) {
                    cout << ans;
                    return 0;
                }
            }
        }
    }
}