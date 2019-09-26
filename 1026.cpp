#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;
int A[50], B[50];
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", A+i);
    for (int i = 0; i < N; i++) scanf("%d", B+i);
    sort(A, A+N);
    sort(B, B+N, greater<int>());
    int ans = 0;
    for (int i = 0; i < N; i++) ans += A[i]*B[i];
    printf("%d\n", ans);
}