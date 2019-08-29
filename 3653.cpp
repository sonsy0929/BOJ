#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1 << 19;
struct segTree {
	int start;
	int sum[SIZE];
	segTree() {
		fill(sum, sum + SIZE, 0);
		start = SIZE / 2;
	}
	void update(int i, int n) {
		i += start;
		while (i) {
			sum[i] += n;
			i /= 2;
		}
	}
	int getSum(int a, int b) {
		return getSum(a, b, 1, 0, start);
	}
	int getSum(int a, int b, int node, int na, int nb) {
		if (b <= na || a >= nb) return 0;
		if (a <= na && nb <= b) return sum[node];
		int mid = (na + nb) / 2;
		return getSum(a, b, node * 2, na, mid) + getSum(a, b, node * 2 + 1, mid, nb);
	}
};
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m, idx[200001];
		scanf("%d %d", &n, &m);
		segTree st;
		for (int i = 1; i <= n; i++) {
			idx[n - (i - 1)] = i;
			st.update(i, 1);
		}
		for (int i = 1; i <= m; i++) {
			int x; scanf("%d", &x);
			printf("%d ", st.getSum(idx[x] + 1, n + m + 1));
			st.update(idx[x], -1);
			idx[x] = n + i;
			st.update(idx[x], 1);
		}
		puts("");
	}
}