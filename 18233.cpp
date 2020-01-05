#include <cstdio>
#include <vector>
using namespace std;
using p = pair<int, int>;
int N, P, E;
vector<int> v;
vector<p> boundaryVector;
bool isPossible(){
    int mn = 0, mx = 0;
    for (int i : v){
        mn += boundaryVector[i].first;
        mx += boundaryVector[i].second;
    }
    return mn <= E && E <= mx;
}
bool comb(int pos, int cnt, vector<int> &ansList){
    if (cnt == P){
        if (isPossible()){
            int sum = 0;
            ansList.resize(N);
            for (int i : v){
                sum += boundaryVector[i].first;
                ansList[i] = boundaryVector[i].first;
            }
            if (sum < E){
                for (int i : v){
                    int diff = boundaryVector[i].second - boundaryVector[i].first;
                    if (E - sum <= 0) break; 
                    int mn = min(E - sum, diff);
                    ansList[i] += mn;
                    sum += mn; 
                }
            }
            return true;
        }
        return false;
    }
    for (int i = pos; i < N; i++){
        v.push_back(i);
        if (comb(i + 1, cnt + 1, ansList)) return true;
        v.pop_back();
    }
    return false;
}
int main(){
    scanf("%d %d %d", &N, &P, &E);
    for (int i = 0; i < N; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        boundaryVector.push_back({x, y}); 
    }
    vector<int> ansList;
    bool possible = comb(0, 0, ansList);
    if (!possible) puts("-1");
    else for (int ans : ansList) printf("%d ", ans);
}