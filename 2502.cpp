/*
Ax + By = k꼴에서 A랑 B는 피보나치 수열 꼴을 이룬다.
이를 이용해서 A와 B를 구하고, 반복문을 돌면서 x에 값을 대입해본다.
(x, y)가 정수꼴을 이룬다면 답이고 O(N)에 구할 수 있다
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int D, K, dp[31] = {1, 1, 2,};
    scanf("%d %d", &D, &K);
    for (int i = 3; i <= 30; i++) dp[i] = dp[i-1] + dp[i-2];
    int i = 1, j = 1;
    bool possible = false;
    for (; i <= 100'000; i++){
        int A = K - (dp[D-3] * i);
        if (A % dp[D-2] == 0){
            j = A / dp[D-2];
            break;
        }
    }
    printf("%d\n%d\n", min(i,j), max(i,j));
}