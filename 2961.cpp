#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
int N, ans = 1e9;
p cook[10];
vector<int> comb;
void f(int p, int n, int k){
    if (n == k){
        int soar = 1, bitter = 0;
        for (int c : comb){
            soar *= cook[c].first;
            bitter += cook[c].second;
        }
        ans = min(ans, abs(soar-bitter));
        return;
    }
    for (int i = p; i < N; i++){
        comb.push_back(i);
        f(i+1,n+1,k);
        comb.pop_back();
    }
}
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d %d", &cook[i].first, &cook[i].second);
    }
    for (int i = 1; i <= N; i++) f(0,0,i);
    printf("%d\n", ans);
}