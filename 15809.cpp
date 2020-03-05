/*
시간복잡도 : O(M log*N) => 대충 O(M)

단순히 dfs로 풀면, 최악의 경우에 skewed한 그래프가 나오면 
100'000 + 99'999 + ... + 2 + 1 이런 식으로 진행을 할 수 있기 때문에
union-find로 path-compression(경로 압축)을 해주었다.
국가(정점)의 번호는 1부터 N까지의 번호이므로,
음수는 사용하지 않는다는 것을 알 수 있다.
따라서, 대표값(root)에 병력의 수를 음수로 저장하는 방식으로 구현을 하면,
단순히 음수라는 사실만으로 root임을 알 수 있고,
병력의 수 또한 저장할 수 있다.
또한, '전쟁'이 일어날 시 병력의 수가 많은 국가가 적은 국가를 흡수하는데,
이 때 대소관계를 |a| < |b|로 강제함으로써 케이스 분류를 하지 않는 방식을 이용했다.
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