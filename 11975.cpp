#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int roff[] = {-1,1,0,0};
const int coff[] = {0,0,-1,1};
int N, dirIdx[128];
bool used[4001][4001];
bool isIN(int r, int c){
    if (r < 0 || c < 0 || r > 4000 || c > 4000) return false;
    return true; 
}
int init(){
    dirIdx['N'] = 0;
    dirIdx['S'] = 1;
    dirIdx['W'] = 2;
    dirIdx['E'] = 3;
}
int main(){
    init();
    string S;
    cin >> N >> S;
    int cr = 2000, cc = 2000;
    used[cr][cc] = true;
    for (char c : S){
        int d = dirIdx[c];
        for (int i = 0; i < 2; i++){
            cr += roff[d];
            cc += coff[d];
            used[cr][cc] = true;
        }
    }
    queue<p> q;
    int cnt = 0;
    for (int i = 0; i <= 4000; i++){
        for (int j = 0; j <= 4000; j++){
            if (used[i][j]) continue;
            q.push({i,j});
            used[i][j] = true;
            cnt++;
            while(!q.empty()){
                auto f = q.front();
                q.pop();
                for (int d = 0; d < 4; d++){
                    int nr = f.first + roff[d];
                    int nc = f.second + coff[d];
                    if (!isIN(nr, nc) || used[nr][nc]) continue;
                    q.push({nr,nc});
                    used[nr][nc] = true;
                }
            }
        }
    }
    cout << cnt-1 << "\n";
}