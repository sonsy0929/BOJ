#include <cstdio>
#include <cmath>
using namespace std;
int N, in[100000];
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", in + i);
    int mn = 2e9 + 1, u, v;
    int l = 0, r = N - 1;
    while (l < r){
        int val = in[l] + in[r];
        if (mn > abs(val)) {
            mn = abs(val);
            u = in[l], v = in[r];
        }
        val >= 0 ? r-- : l++;
    }
    printf("%d %d\n", u, v);
}