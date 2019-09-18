#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int SIZE = 50'001;
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> v;
    for (int i = 0; i < n; i++){
        int in;
        scanf("%d", &in);
        v.push_back(in);
    }
    sort(v.begin(), v.end());
    int left[SIZE]{}, right[SIZE]{};
    for (int i = 0; i < n; i++){
        auto uit = upper_bound(v.begin() + i, v.end(), v[i]+k);
        left[i] = uit - (v.begin() + i);
    }
    int mx = 0, ans = 0;
    for (int i = n - 1; i >= 0; i--){
        mx = max(mx, left[i]);
        right[i] = mx;
    }
    for (int i = 0; i < n; i++){
        ans = max(ans, left[i] + right[i + left[i]]);
    }
    printf("%d\n", ans);
}