#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
struct LRU {
    int N, priority;
    map<char, int> f;
    map<int, char> g;
    LRU(int N) : N(N), priority(0) {}
    void refer(char c) {
        if (f.count(c)) {
            g.erase(f[c]);
        }
        if (g.size() == N) {
            f.erase(g.begin()->second);
            g.erase(g.begin());
        }
        f[c] = priority;
        g[priority++] = c;
    }
    void print() {
        for (auto [w, c] : g) cout << c;
        cout << "\n";
    }
};
int main() {
    fastio;
    int N, num = 1;
    while (cin >> N && N != 0) {
        cout << "Simulation " << num++ << "\n";
        string command;
        cin >> command;
        LRU lru(N);
        for (char c : command) {
            if (c == '!') {
                lru.print();
                continue;
            }
            lru.refer(c);
        }
    }
}