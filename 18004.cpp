/*
�׸��� �˰���

i) A > B : 
Ȧ���̸� +1�� �ؼ� ¦���� �����, ¦���̸� /2�� �ϴ°� �̵��� �����̴�.
ii) A < B :
���ϴ� ��� ����� �� �� �ִ°� ����.
*/

#include <bits/stdc++.h>
using namespace std;
int A, B;
int main() {
    int cnt = 0;
    scanf("%d %d", &A, &B);
    while (A > B) {
        if (A & 1) A++;
        else A /= 2;
        cnt++;
    }
    printf("%d", B - A + cnt);
}