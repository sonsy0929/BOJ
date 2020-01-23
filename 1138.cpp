/*
그리디 or 순열
idea : 빈 칸은 해당 수보다 큰 숫자라 생각하고, 수가 작은 수부터 먼저 자리에 배치하자!
*/
#include <bits/stdc++.h>
using namespace std;
int N, A[11];
int main(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        int k;
        scanf("%d", &k);
        int p = 1;
        for (int j = 1; j <= k; j++){
            while(A[p]) p++;
            p++;
        }
        while(A[p]) p++;
        A[p] = i;
    }
    for (int i = 1; i <= N; i++) printf("%d ", A[i]);
}