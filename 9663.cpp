#include <cstdio>
using namespace std;
int C[30],I[30],D[30],N,ans;
void f(int r){
    if (r == N){
        ans++;
        return;
    }
    for (int i = 0; i < N; i++){
        if (C[i] || I[r+i] || D[N-1+(r-i)]) continue;
        C[i] = I[r+i] = D[N-1+(r-i)] = true;
        f(r+1);
        C[i] = I[r+i] = D[N-1+(r-i)] = false;
    }
}
int main(){
    scanf("%d", &N);
    f(0);
    printf("%d\n", ans);
}