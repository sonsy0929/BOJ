/*
�׸��� or ����
idea : �� ĭ�� �ش� ������ ū ���ڶ� �����ϰ�, ���� ���� ������ ���� �ڸ��� ��ġ����!
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