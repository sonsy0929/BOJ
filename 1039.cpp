#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;
int main() {
    string S;
    int K;
    cin >> S >> K;
    queue<string> q;
    q.push(S);
    int ans = -1;
    for (int k = 0; k < K + 1; k++) {
        int qSize = q.size();
        set<string> used;
        for (int s = 0; s < qSize; s++) {
            string curr = q.front();
            q.pop();
            if (k == K) {
                ans = max(ans, stoi(curr));
            }
            for (int i = 0; i < S.size(); i++) {
                for (int j = i + 1; j < S.size(); j++) {
                    string next = curr;
                    swap(next[i], next[j]);
                    if (used.count(next) || next.front() == '0') continue;
                    used.insert(next);
                    q.push(next);
                }
            }
        }
    }
    cout << ans << "\n";
}