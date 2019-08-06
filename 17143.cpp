#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int, int>;
struct FISH {
    int s, d, z;
    bool isEat;
};
const int roff[] = {-1, 1, 0, 0};
const int coff[] = {0, 0, 1, -1};
int main(){
    int R, C, K;
    scanf("%d %d %d", &R, &C, &K);
    FISH map[101][101] = {0, 0, 0, false};
    vector<p> info;
    for (int i = 0; i < K; i++) {
        int r, c, s, d, z;
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        map[r][c] = {s, d - 1, z, false};
        info.push_back({r, c});
    }
    int ans = 0;
    for (int j = 1; j <= C; j++){
        FISH newMap[101][101] = {0, 0, 0, false};
        for (int i = 1; i <= R; i++){
            if (map[i][j].z) {
                ans += map[i][j].z;
                map[i][j].isEat = true;
                break;
            }
        }
        for (auto &pCurr : info){
            int &r = pCurr.first;
            int &c = pCurr.second;
            if (map[r][c].isEat) continue;
            int s, d, z;
            s = map[r][c].s;
            d = map[r][c].d;
            z = map[r][c].z;
            if (d < 2){
                int l = s;
                l %= (R - 1) * 2;
                while(l--){
                    if (r <= 1) d = 1;
                    if (r >= R) d = 0;
                    r += roff[d];
                }
            }
            else {
                int l = s;
                l %= (C - 1) * 2;
                while (l--){
                    if (c <= 1) d = 2;
                    if (c >= C) d = 3;
                    c += coff[d];
                }
            }
            if (newMap[r][c].z > z) continue;
            newMap[r][c].d = d;
            newMap[r][c].s = s;
            newMap[r][c].z = z; 
        }
        swap(newMap, map);
    }
    printf("%d\n", ans);
}