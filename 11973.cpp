#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n, k;
bool f(int m){
    int cnt = k;
    auto pos = v.begin();
    while (pos != v.end()){
        pos = upper_bound(v.begin(), v.end(), (*pos) + 2 * m);
        cnt--;
    }
    return cnt >= 0;
}
int main(){
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        int in;
        scanf("%d", &in);
        v.push_back(in);
    }
    sort(v.begin(), v.end());
    int lo = 0, hi = 1e9;
    while (lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if (f(mid)) hi = mid;
        else lo = mid;
    }
    printf("%d\n", hi);
}