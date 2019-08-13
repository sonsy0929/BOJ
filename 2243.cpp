#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1 << 21;
struct segTree {
	int start;
	int candy[SIZE];
	segTree() {
		start = SIZE / 2;
		fill(candy, candy + SIZE, 0);
	}
	void update(int i, int val) {
		i += start;
		candy[i] += val;
		while (i) {
			i /= 2;
			candy[i] = candy[i * 2] + candy[i * 2 + 1];
		}
	}
	int kth(int n, int k) {
		if (n >= start) return n - start;
		int pivot = candy[n * 2];
		if (pivot >= k) return kth(n * 2, k);
		return kth(n * 2 + 1, k - pivot);
	}
};
int main() {
	int N; scanf("%d", &N);
	segTree st;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		scanf("%d", &a);
		if (a == 2) {
			scanf("%d %d", &b, &c);
			st.update(b - 1, c);
		}
		else {
			scanf("%d", &b);
			int rank = st.kth(1, b);
			printf("%d\n", rank + 1);
			st.update(rank, -1);
		}
	}
}