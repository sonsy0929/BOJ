#include <cstdio>
#include <vector>
using namespace std;
using p = pair<int,int>;
int main(){
    int n;
    scanf("%d", &n);
    vector<p> v;
    for (int i = 1; i <= n; i++){
        int in;
        scanf("%d", &in);
        v.push_back({i,in});
    }
    int curr = 0, S = v.size();
    while (1){
        printf("%d ", v[curr].first);
        int move = v[curr].second;
        v.erase(v.begin() + curr);
        if (--S == 0) break;
        if (move < 0) curr += S + move % S;
        else curr += move - 1;
        curr %= S;
    }
}