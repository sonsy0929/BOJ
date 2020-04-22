/*
오리와 육리가 이동할 때, 

1) 거리가 유지
2) 거리가 가까워짐
3) 거리가 멀어짐

위 3가지 방법이 존재한다. 당연히도, 오리와 육리가 만나는 최소의 시간을 구해야 하므로
3)의 경우는 무시하는게 자명하다.

오리와 육리의 거리 차를 diff라 하면, 거리가 가까워질 때를 생각해보자.
거리가 가까워질 때 각자 2^(t-1)만큼 이동하게 되어, 서로의 간격 차이는 diff - 2^t만큼 생긴다.
결국, 서로 만난다는 것은 간격 차이가 0이라는 것과 같은 표현이며, 
diff == 2^t + 2^(t+1) + ...(단, t >= 1이며 비트마스킹으로 표현했을 때 1인 부분만 더한다)
와 같이 표현할 수 있다.

예제를 살펴보면, 10, 4, 10의 input이 주어진다.
diff = 10 - 4이며, 이진수로 표현했을 때 110(2)로 표현할 수 있다.
즉, 1일차와 2일차 때 이동해야 2 + 4 = 6칸 만큼 이동할 수 있다는 것이다.
그래서 위 input의 output으로는 2가 나오게된다.
*/

#include <bits/stdc++.h>
using namespace std;
int N, A, B, diff, ans = 1e9;
void f(int a, int b, int t) {
    if (a <= 0 || a > N || b <= 0 || b > N) return;
    if (a == b) ans = min(ans, t);
    int j = 1 << t;
    if (diff & 2 << t) {
        f(a + j, b - j, t + 1);
        return;
    }
    f(a + j, b + j, t + 1);
    f(a - j, b - j, t + 1);
}
int main() {
    cin >> N >> A >> B;
    if (A > B) swap(A, B);
    diff = B - A;
    if (diff & 1) return !printf("-1");
    f(A, B, 0);
    if (ans != 1e9) cout << ans;
    else cout << -1;
}