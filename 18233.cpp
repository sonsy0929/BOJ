/*
시간복잡도 : O(2^20)

선택, 비선택의 방식을 비트마스킹을 통해 구현을 했다.
예제 입력 2 같은 경우 5명의 회원 중에 2명을 골라야 하는데,
이를 비트로 표현을 하면 00011(2), 00101(2), 01001(2), ... 이런 식으로 표현을 할 수 있다.
즉 1의 개수가 P개이면 되므로, __builtin_popcount 함수를 통해 1의 개수를 세주었다.
이후, 각 회원이 요구하는 최소값과 최대값을 각각 더해서, E개의 인형을 나누어 줄 수 있는지 확인을 하였다.
sum(xi) <= E <= sum(yi)이면 E개의 인형을 나누어 줄 수 있는 것이므로, 이 경우에만 가능한 경우를 찾아주면 된다.
*/

#include <bits/stdc++.h>
using namespace std;
int N, P, E, x[20], y[20];
int main() {
    scanf("%d %d %d", &N, &P, &E);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", x + i, y + i);
    }
    vector<int> ans;
    for (int b = 1; b < (1 << N); b++) {
        if (__builtin_popcount(b) != P) continue;
        vector<int> tracking(N, 0);
        int sum = 0, xSum = 0, ySum = 0;
        for (int i = 0; i < N; i++) {
            if (b & (1 << i)) {
                tracking[i] += x[i];
                sum += x[i];
                xSum += x[i], ySum += y[i];
            }
        }
        if (xSum <= E && E <= ySum) {
            for (int i = 0; i < N; i++) {
                if (!tracking[i]) continue;
                int add = min(y[i] - x[i], E - sum);
                tracking[i] += add;
                sum += add;
            }
            ans = tracking;
            break;
        }
    }
    if (ans.empty()) {
        puts("-1");
    } else {
        for (int curr : ans) {
            printf("%d ", curr);
        }
    }
}