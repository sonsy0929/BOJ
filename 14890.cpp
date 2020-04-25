/*
�ð����⵵ : O(N^2)

��� ���� ���� ���� �˻縦 �ϸ� �ȴ�.
�� ��, ���θ� �ٽ� �Ǽ��� �� ������ used �迭�� �̿��ؼ� �̸� ó�����־���.
*/

#include <bits/stdc++.h>
using namespace std;
int N, L, maze[110][110];
bool isPossible(vector<int> &road) {
    bool ret = true, used[110]{};
    int sz = road.size();
    for (int i = 0; i < sz - 1; i++) {
        int d = road[i+1] - road[i];
        if (d == -1) {
            int pos = i + 1, t = road[pos];
            while (pos < N && t == road[pos]) pos++;
            ret &= pos - (i + 1) >= L;
            if (ret) {
                for (int j = i + 1; j < i + 1 + L; j++) {
                    ret &= !used[j];
                    used[j] = true;
                }
            }
        }
        if (d == 1) {
            int pos = i, t = road[pos];
            while (pos >= 0 && t == road[pos]) pos--;
            ret &= i - pos >= L;
            if (ret) {
                for (int j = i + 1 - L; j < i + 1; j++) {
                    ret &= !used[j];
                    used[j] = true;
                }
            }
        }
        ret &= abs(d) < 2;
    }
    return ret;
}
int main() {
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < N; j++) {
            v.push_back(maze[i][j]);
        }
        ans += isPossible(v);
        v.clear();
        for (int j = 0; j < N; j++) {
            v.push_back(maze[j][i]);
        }
        ans += isPossible(v);
    }
    printf("%d", ans);
}