#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int, int>;
const int SIZE = 1 << 17;
struct segTree {
	int mx[SIZE];
	int start;
	segTree(int n) {
		memset(mx, 0, sizeof(mx));
		for (start = 1; start < n; start <<= 1);
	}
	void update(int i, int val) {
		i += start;
		mx[i] = val;
		while (i) {
			i /= 2;
			mx[i] = max(mx[i * 2], mx[i * 2 + 1]);
		}
	}
	int getRainVal(int i) {
		return mx[i + start];
	}
	int getMax(int l, int r) {
		return getMax(l, r, 1, 0, start);
	}
	int getMax(int l, int r, int node, int nl, int nr) {
		if (nr <= l || r <= nl) return 0;
		if (l <= nl && nr <= r) return mx[node];
		int mid = (nl + nr) / 2;
		return max(getMax(l, r, node * 2, nl, mid), getMax(l, r, node * 2 + 1, mid, nr));
	}
};
int main() {
	int n, m;
	scanf("%d", &n);
	segTree st(n);
	map<int, int> mp;
	vector<int> boundary;
	vector<p> in;
	for (int i = 1; i <= n; i++) {
		int y, r;
		scanf("%d %d", &y, &r);
		in.push_back({ y, r });
		boundary.push_back(y);
	}
	sort(in.begin(), in.end());
	int pos = 1;
	for (auto pCurr : in) {
		int y = pCurr.first;
		int r = pCurr.second;
		mp[y] = pos;
		st.update(pos - 1, r);
		pos++;
	}
	scanf("%d", &m);
	sort(boundary.begin(), boundary.end());
	for (int i = 0; i < m; i++) {
		int y, x;
		scanf("%d %d", &y, &x);
		if (mp[x] && mp[y]) {
			int xRain = st.getRainVal(mp[x] - 1);
			int yRain = st.getRainVal(mp[y] - 1);
			auto xIdx = lower_bound(boundary.begin(), boundary.end(), x);
			auto yIdx = lower_bound(boundary.begin(), boundary.end(), y);
			int SIZE = xIdx - yIdx;
			if (xRain <= yRain && xRain > st.getMax(mp[y], mp[x] - 1)) {
				if (x - y == SIZE) puts("true");
				else puts("maybe");
			}
			else puts("false");
		}
		else if (mp[x]) {
			int yIdx = lower_bound(boundary.begin(), boundary.end(), y) - boundary.begin();
			int xRain = st.getRainVal(mp[x] - 1);
			int Y = mp[boundary[yIdx]];
			if (xRain > st.getMax(Y - 1, mp[x] - 1)) puts("maybe");
			else puts("false");
		}
		else if (mp[y]) {
			int xIdx = lower_bound(boundary.begin(), boundary.end(), x) - boundary.begin();
			int yRain = st.getRainVal(mp[y] - 1);
			int X = mp[boundary[xIdx - 1]];
			if (yRain <= st.getMax(mp[y], X)) puts("false");
			else puts("maybe");
		}
		else puts("maybe");
	}
}