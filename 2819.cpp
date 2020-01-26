#include <bits/stdc++.h>
using namespace std;
int N, M, X[100'000], Y[100'000];
struct point {
    int x, y;
    point() : x(0), y(0) {}
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string command;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        X[i] = x, Y[i] = y;
    }
    sort(X, X + N);
    sort(Y, Y + N);
    cin >> command;
    point curr, prev;
    long long xSum = 0, ySum = 0;
    for (int i = 0; i < N; i++) {
        xSum += abs(X[i]);
        ySum += abs(Y[i]);
    }
    for (int i = 0; i < command.size(); i++) {
        char c = command[i];
        if (c == 'S') curr.y++;
        if (c == 'J') curr.y--;
        if (c == 'I') curr.x++;
        if (c == 'Z') curr.x--;
        if (prev.x < curr.x) {
            int k = lower_bound(X, X + N, curr.x) - X;
            xSum += k - (N - k);
        }
        if (prev.x > curr.x) {
            int k = lower_bound(X, X + N, prev.x) - X;
            xSum += (N - k) - k;
        }
        if (prev.y < curr.y) {
            int k = lower_bound(Y, Y + N, curr.y) - Y;
            ySum += k - (N - k);
        }
        if (prev.y > curr.y) {
            int k = lower_bound(Y, Y + N, prev.y) - Y;
            ySum += (N - k) - k;
        }
        cout << xSum + ySum << "\n";
        prev = curr;
    }
}