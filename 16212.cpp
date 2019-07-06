#include <cstdio>
#include <algorithm>
using namespace std;
int n, v[500000];
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", v + i);
    sort(v, v + n);
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
}