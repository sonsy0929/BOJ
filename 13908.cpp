#include <cstdio>
using namespace std;
/*
포함 배제의 원리를 이용한 풀이
 */
int f(int param, int n){
    int ret = 1;
    for (int i = 0; i < n; i++) ret *= param;
    return ret;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = 0;
    for (int i = 0; i < 1 << m; i++){
        int sign = 1, cnt = 0;
        for (int j = 0; j < m; j++){
            if (i & 1 << j) {
                cnt++;
                sign *= -1;
            }
        }
        ans += sign * f(10 - cnt, n);
    }
    printf("%d\n", ans);
}