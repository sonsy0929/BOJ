#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
const int SIZE = 500'001;
int v[SIZE], sorted[SIZE];
ll ans;
void merge(int l, int mid, int r){
    int nl = l, nr = mid, p = l;
    while (nl < mid && nr < r){
        if (v[nl] <= v[nr]) sorted[p++] = v[nl++];
        else{
            ans += mid - nl;
            sorted[p++] = v[nr++];
        }
    }
    if (nl < mid){
        for (int i = nl; i < mid; i++) sorted[p++] = v[i];
    }
    else{
        for (int i = nr; i < r; i++) sorted[p++] = v[i];
    }
    for (int i = l; i < r; i++) v[i] = sorted[i];
}
void mergesort(int l, int r){
    if (l + 1 < r){
        int mid = (l + r) / 2;
        mergesort(l, mid);
        mergesort(mid, r);
        merge(l, mid, r);
    }
}
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", v + i);
    mergesort(0, N);
    printf("%lld\n", ans);
}