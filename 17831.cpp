/*
dp[curr][hasMento] : curr�� curr�� �����
���丵�� ���� ��,
Ȥ�� ���丵�� ���� ���� ��,
curr�� '����Ʈ��'������ �ó����� ���� �ִ밪

i) curr�� curr�� ����� ���丵�� ���� ��
curr�� �̹� ���䰡 ������, curr�� �λ������ curr�� ���丵�� ���� �� ����.
����, curr�� �λ������ '����Ʈ��'���� ���� �����ָ� �ȴ�.
curr�� �λ������ C1, C2, C3, C4 ... ��� �Ѵٸ�

dp[curr][1] = sum of dp[Cx][0] (1 <= x <= k)

ii) curr�� curr�� ����� ���丵�� ���� ���� ��
i)���� �߰���, curr�� curr�� �λ�� �Ѹ��� ���丵�� �ϴ� ��쵵 ����ؾ� �Ѵ�.
dp[curr][0] = max{
    
    sum of dp[Cx][0] => curr�� �ƹ��͵� ���丵 ���� ����

    �Ƿ�[curr] * �Ƿ�[C1] + dp[C1][1] + dp[C2][0] + ... => curr�� C1�� ���丵�� ����
    �Ƿ�[curr] * �Ƿ�[C2] + dp[C1][0] + dp[C2][1] + ... => curr�� C2�� ���丵�� ����
    ...
}

�Ƿ�[curr] * �Ƿ�[C1] + dp[C1][1] + dp[C2][0] + ... (1)
�Ƿ�[curr] * �Ƿ�[C2] + dp[C1][0] + dp[C2][1] + ... (2)
...

�� ���� ������ ���ϸ� O(C^2)�� �ð��� �ҿ�Ǿ� �ʹ� ���� �ɸ���.
����, S = dp[C1][0]+ dp[C2][0] + dp[C3][0] + ...�� �̸� O(C)�� ���س���,

(1) = S - dp[C1][0] + dp[C1][1] + �Ƿ�[curr] * �Ƿ�[C1]
(2) = S - dp[C2][0] + dp[C2][1] + �Ƿ�[curr] * �Ƿ�[C2]

�̷� ������� ���Ѵٸ�, �ϳ��� O(1)�� ���� �� �ִ�.
*/

#include <bits/stdc++.h>
using namespace std;
const int SIZE = 200'010;
int N, dp[SIZE][2], score[SIZE];
vector<int> adj[SIZE];
int f(int curr, bool select) {
    int &ret = dp[curr][select];
    if (ret != -1) return ret;
    int sum = 0;
    for (int next : adj[curr]) {
        sum += f(next, false);
    }
    ret = sum;
    if (!select) {
        for (int next : adj[curr]) {
            int val = score[next] * score[curr];
            ret = max(ret, sum - f(next, false) + f(next, true) + val);
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 2; i <= N; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for (int i = 1; i <= N; i++) cin >> score[i];
    memset(dp, -1, sizeof(dp));
    cout << f(1, false) << "\n";
}