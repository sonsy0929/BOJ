/*
Ax + By = k�ÿ��� A�� B�� �Ǻ���ġ ���� ���� �̷��.
�̸� �̿��ؼ� A�� B�� ���ϰ�, �ݺ����� ���鼭 x�� ���� �����غ���.
(x, y)�� �������� �̷�ٸ� ���̰� O(N)�� ���� �� �ִ�
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