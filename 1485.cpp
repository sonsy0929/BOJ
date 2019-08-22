#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using p = pair<int,int>;
int getDist(p u, p v){
    return pow(u.first - v.first, 2) + pow(u.second - v.second, 2);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int u, v;
        vector<ll> line;
        p dot[4];
        for (int i = 0; i < 4; i++){
            scanf("%d %d", &u, &v);
            dot[i] = {u, v};
        }
        for (int i = 0; i < 4; i++){
            for (int j = i + 1; j < 4; j++){
                line.push_back(getDist(dot[i], dot[j]));
            }
        }
        sort(line.begin(), line.end());
        bool ret = true;
        for (int i = 0; i < 3; i++) ret &= (line[i] == line[i + 1]);
        ret &= (line[4] == line[5]);
        printf("%d\n", ret);
    }
}