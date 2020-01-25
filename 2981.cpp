/*
고등 수학 때 배운 나머지 정리에 의하면
a[i] = MQ[i] + d 꼴로 표현을 할 수 있다.
a[n] = MQ[n] + d
a[n+1] = MQ[n+1] + d이므로
a[n+1] - a[n] = M(Q[n+1] - Q[n]) 꼴이 나온다.
즉, a[n+1] - a[n] = k라 하면, M은 k의 약수라는 점을 위의 등식을 통해 알 수 있다.
이를 통해, 각각의 차에서 최대공약수를 구해
그 최대공약수의 약수를 구하면 M을 모두 찾을 수 있다!
*/
#include <bits/stdc++.h>
using namespace std;
int N, A[100];
int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", A + i);
    sort(A, A + N);
    int GCD = A[1] - A[0];
    for (int i = 2; i < N; i++) {
        GCD = gcd(GCD, A[i] - A[i - 1]);
    }
    vector<int> ans;
    for (int i = 2; i * i <= GCD; i++) {
        if (GCD % i == 0) {
            ans.push_back(i);
            if (i * i != GCD) ans.push_back(GCD / i);
        }
    }
    ans.push_back(GCD);
    sort(ans.begin(), ans.end());
    for (int curr : ans) printf("%d ", curr);
}