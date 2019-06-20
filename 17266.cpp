#include <cstdio>
using namespace std;
const int MAX = 100000;
int n, m, v[MAX];
bool possible(int param){
    for (int i = 1; i < m - 1; i++){
        if (v[i] + param < v[i + 1] - param) return false;
    }
    if (v[0] - param > 0 ||
    v[m - 1] + param < n) return false;
    return true;
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d", v + i);
    int lo = 0, hi = MAX + 1;
    while (lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if (possible(mid)) hi = mid;
        else lo = mid;
    }
    printf("%d\n", hi);
}