#include <cstdio>
#include <algorithm>
using namespace std;
int in[20001];
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", in + i);
    sort(in, in + N);
    printf("%d\n", in[(N - 1) / 2]);
}