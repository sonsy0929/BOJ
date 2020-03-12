/*
시간복잡도 : O(W^2)

물이 고이려면, 왼쪽과 오른쪽에 고이려는 위치보다 큰 벽이 있어야 한다.
각 지점마다, 왼쪽(L)과 오른쪽(R)의 최대 높이를 확인하고
max(0, min(L, R) - '지점의 높이')를 더해주면 된다.
*/
#include <bits/stdc++.h>
using namespace std;
int H, W;
int main() {
    scanf("%d %d", &H, &W);
    vector<int> B(W, 0);
    for (int i = 0; i < W; i++) {
        scanf("%d", &B[i]);
    }
    int ans = 0;
    for (int i = 1; i < W; i++) {
        int L = 0, R = 0;
        for (int l = 0; l < i; l++) L = max(L, B[l]);
        for (int r = W - 1; r > i; r--) R = max(R, B[r]);
        ans += max(0, min(L, R) - B[i]);
    }
    printf("%d", ans);
}