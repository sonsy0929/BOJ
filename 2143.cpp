#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int t, n, m;
int A[1000], B[1000];
int getSum(int param[1000], vector<int> &v, int bound) {
    for (int i = 0; i < bound; i++){
        int sum = 0;
        for (int j = i; j < bound; j++){
            sum += param[j];
            v.push_back(sum);
        }
    }
}
int main(){
    vector<int> aSum, bSum;
    scanf("%d", &t);    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", A + i);    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", B + i);
    getSum(A, aSum, n);
    getSum(B, bSum, m);
    sort(bSum.begin(), bSum.end());
    ll ans = 0;
    for (int curr : aSum){
        int lo = lower_bound(bSum.begin(), bSum.end(), t - curr) - bSum.begin();
        int hi = upper_bound(bSum.begin(), bSum.end(), t - curr) - bSum.begin();
        if (bSum[lo] == t - curr) ans += hi - lo;
    }
    printf("%lld\n", ans);
}