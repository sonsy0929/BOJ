#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int N, in[100000];
int _binarySearch(int lo, int hi, int val){
    while (lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if (in[mid] <= val) lo = mid;
        else hi = mid;  
    }
    int u = abs(in[lo] - val);
    int v = abs(in[hi] - val);
    if (in[lo] == -val) return hi;
    else if (in[hi] == -val) return lo;
    return u > v ? hi : lo;
}
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", in + i);
    int mn = 2e9 + 1;
    int u = 0, v = 0;
    for (int i = 0; i < N; i++){
        int idx = _binarySearch(0, N - 1, -in[i]);
        int diff = abs(in[i] + in[idx]);
        if (mn > diff) {
            mn = diff;
            u = in[i], v = in[idx];
        }
    }
    printf("%d %d", u, v);
}