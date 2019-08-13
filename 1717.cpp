#include <cstdio>
#include <cstring>
using namespace std;
int uf[1000001];
int find(int p){
    if (uf[p] < 0) return p;
    return uf[p] = find(uf[p]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    uf[a] = b;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    memset(uf, -1, sizeof(uf));
    for (int i = 0; i < m; i++){
        int k, a, b;
        scanf("%d %d %d", &k, &a, &b);
        if (!k) merge(a, b);
        else {
            if (find(a) != find(b)) puts("NO");
            else puts("YES");
        }
    }
}