/*
그리디 알고리즘

i) A > B : 
홀수이면 +1을 해서 짝수로 만들고, 짝수이면 /2를 하는게 이득인 구조이다.
ii) A < B :
더하는 방법 말고는 할 수 있는게 없다.
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