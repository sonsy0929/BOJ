/*
���ش� "������, ť, �����̵� ������"�̴�.
��κ��� �ҽ����� �����̵� ������� �Ǿ� �ִµ�,
���� �ٸ� Ǯ�̰� ���ö� �̷� ������� Ǯ����.
���� �̸��� ���̸� �������� ������ �־��ش�.
�� �� ������ �ڵ����� ������������ ������ �Ǵµ�,
�̸� �̿��Ͽ� upper_bound�� ����ؼ� ���� ģ���� �ĺ����� �� ������ ������.
����, �� ģ���� �ش��ϴ� ���� ģ���� ���� �����־� ���� ������ count���־���.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> RANK[300'000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        RANK[in.size()].push_back(i);
    }
    long long ans = 0;
    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j < RANK[i].size(); j++) {
            int curr = RANK[i][j];
            auto uit = upper_bound(RANK[i].begin(), RANK[i].end(), curr + K);
            if (uit != RANK[i].end()) {
                int idx = uit - RANK[i].begin();
                ans += idx - j - 1;
            } else {
                ans += RANK[i].size() - j - 1;
            }
        }
    }
    cout << ans << "\n";
}