#include <bits/stdc++.h>
using namespace std;
constexpr int GOAL = 32;
int dice[10];
int go[33][6] = {
    {0, 1, 2, 3, 4, 5},  // 0
    {2, 2, 3, 4, 5, 6},
    {4, 3, 4, 5, 6, 7},
    {6, 4, 5, 6, 7, 8},
    {8, 5, 6, 7, 8, 9},
    {10, 21, 22, 23, 24, 30},  // 5
    {12, 7, 8, 9, 10, 11},
    {14, 8, 9, 10, 11, 12},
    {16, 9, 10, 11, 12, 13},
    {18, 10, 11, 12, 13, 14},
    {20, 28, 29, 24, 30, 31},  // 10
    {22, 12, 13, 14, 15, 16},
    {24, 13, 14, 15, 16, 17},
    {26, 14, 15, 16, 17, 18},
    {28, 15, 16, 17, 18, 19},
    {30, 27, 26, 25, 24, 30},  // 15
    {32, 17, 18, 19, 20, 32},
    {34, 18, 19, 20, 32, 32},
    {36, 19, 20, 32, 32, 32},
    {38, 20, 32, 32, 32, 32},
    {40, 32, 32, 32, 32, 32},  // 20
    {13, 22, 23, 24, 30, 31},
    {16, 23, 24, 30, 31, 20},
    {19, 24, 30, 31, 20, 32},
    {25, 30, 31, 20, 32, 32},  // 24
    {26, 24, 30, 31, 20, 32},  // 25
    {27, 25, 24, 30, 31, 20},
    {28, 26, 25, 24, 30, 31},
    {22, 29, 24, 30, 31, 20},  // 28
    {24, 24, 30, 31, 20, 32},
    {30, 31, 20, 32, 32, 32},  // 30
    {35, 20, 32, 32, 32, 32},
    {0, 32, 32, 32, 32, 32},
};
int f(int state) {
    int pos[4]{}, ret = 0;
    bool visited[40]{};
    visited[0] = true;
    for (int i = 0; i < 10; i++) {
        int player = state & 3;
        int& curr = pos[player];
        int next = go[curr][dice[i]];
        if (visited[next] && next && next != GOAL) return 0;
        ret += go[next][0];
        visited[next] = true;
        visited[curr] = false;
        curr = next;
        state >>= 2;
    }
    return ret;
}
int main() {
    for (int i = 0; i < 10; i++) scanf("%d", dice + i);
    int ans = 0;
    for (int b = 0; b < (1 << 20); b++) {
        ans = max(ans, f(b));
    }
    printf("%d\n", ans);
}