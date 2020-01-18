#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
p cow[20000];
int main(){
    int C, N;
    scanf("%d %d",&C,&N);
    multiset<int> ms;
    for (int i = 0; i < C; i++){
        int in;
        scanf("%d", &in);
        ms.insert(in);
    }
    for (int i = 0; i < N; i++){
        int a, b;
        scanf("%d %d",&a,&b);
        cow[i] = {b,a};
    }
    sort(cow, cow+N);
    int ans = 0;
    for (int i = 0; i < N; i++){
        auto iter = ms.lower_bound(cow[i].second);
        if (iter != ms.end() && *iter <= cow[i].first){
            ans++;
            ms.erase(iter);
        }
    }
    printf("%d\n", ans);
}