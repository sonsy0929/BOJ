/*
진짜 문제를 제대로 읽어야 했던 것을 뼈저리게 느낀 문제

Green55님 해설
(1,1) ~ (r,c)로 직사각형 모양의 범위를 하나 잡고, 해당 범위의 수를 전부 토글 시킬 수 있다.
최소의 횟수로 전부 0을 만들어야 한다.
토글을 고려하는 순서는 오른쪽 아래(R,C)에서 왼쪽 위(1,1) 방향으로 정한다.
(r,c)를 뒤집을 수 있는 경우는 (1,1) ~ (r,c)를 전부 뒤집는 것 딱 하나뿐이다.
따라서, (r,c)가 1이면 반드시 뒤집어야 하고, 0이면 뒤집어서는 안된다.
이제 (r, c-1)을 보면, (r, c-1)을 뒤집을 수 있는 경우는 (r,c)와 (r,c-1)이다.
그런데 이미 (r,c)를 이미 뒤집었으므로, 역시 (r,c-1)이 1이면 뒤집어야 하고 0이면 뒤집지 말아야 한다.
이렇게 모든 좌표에 대해 뒤집을지 말지에 대해서 결정하고, 그대로 시뮬레이션 하면 된다.
*/

#include <cstdio>
using namespace std;
int herd[10][10];
void toggle(int r, int c){
    for (int i = 0; i <= r; i++){
        for (int j = 0; j <= c; j++){
            herd[i][j] = 1 - herd[i][j];
        }
    }
}
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%1d", &herd[i][j]);
        }
    }
    int ans = 0;
    for (int i = N - 1; i >= 0; i--){
        for (int j = N - 1; j >= 0; j--){
            if (herd[i][j]){
                toggle(i,j);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}