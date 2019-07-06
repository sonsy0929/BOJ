#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int six[50]{}, one[50]{};
    for (int i = 0; i < m; i++){
        int s, o;
        scanf("%d %d", &s, &o);
        six[i] = s;
        one[i] = o;
    }
    sort(six, six + m);
    sort(one, one + m);
    int Q = n / 6, B = n % 6;
    int ans = min({Q * six[0] + B * one[0], n * one[0], (Q + 1) * six[0]});
    printf("%d\n", ans);
}