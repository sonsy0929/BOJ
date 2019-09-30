#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
int main(){
    int N;
    scanf("%d", &N);
    vector<p> v(N);
    for (int i = 0; i < N; i++){
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for (int i = 0; i < N; i++){
        ans = max(ans, v[i].second - i);
    }
    printf("%d\n", ans+1);
}