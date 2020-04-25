/*
�ð����⵵ : �ϳ��� ��ǥ�� ���� ������ �ڶ� �� �־ �����ϱ� ����..

idea : deque�� �̿��� �׻� ������ �Ǿ��ִ� ���¸� ��������
�Ǽ��ϱ� ���� �κ� : �����Ҵ��� �Ͼ�� �ʰ� �����ؾ� �Ѵ�.

��ũ���ǿ� ���� �������, ��, ����, ����, �ܿ� ���� �����ϸ� �ȴ�.
�� ��, �׻� ������������ ������ ������ ���¸� �����ϱ� ����, 
���̰� ���(���糪�� + 1) �ڿ��� �־��ְ�(push_back) ������ ����(���� 1)�� �տ��� �־��ش�(push_front) 
*/

#include <bits/stdc++.h>
using namespace std;
const int roff[] = {-1, 0, 1, 0, -1, 1, -1, 1};
const int coff[] = {0, 1, 0, -1, -1, -1, 1, 1};
int N, M, K, A[13][13], ground[13][13];
bool isIn(int r, int c) {
    return r >= 0 && c >= 0 && r < N && c < N;
}
int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
            ground[i][j] = 5;
        }
    }
    deque<int> tree[13][13];
    for (int i = 0; i < M; i++) {
        int r, c, age;
        scanf("%d %d %d", &r, &c, &age);
        tree[r-1][c-1].push_back(age);
    }
    for (int k = 0; k < K; k++) {
        vector<int> trash[13][13];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                deque<int> nxt;
                for (int age : tree[i][j]) {
                    if (age > ground[i][j]) {
                        trash[i][j].push_back(age);
                        continue;
                    }
                    ground[i][j] -= age;
                    nxt.push_back(age + 1);
                }
                swap(nxt, tree[i][j]);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int age : trash[i][j]) {
                    ground[i][j] += age / 2;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int age : tree[i][j]) {
                    if (age % 5) continue;
                    for (int d = 0; d < 8; d++) {
                        int nr = i + roff[d], nc = j + coff[d];
                        if (!isIn(nr, nc)) continue;
                        tree[nr][nc].push_front(1);
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ground[i][j] += A[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += tree[i][j].size();
        }
    }
    printf("%d", ans);
}