#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int MAXSIZE = 15;
constexpr int INF = 0x3fffffff;
int main(){
    int n, start;
    scanf("%d %d", &n, &start);
    int cost[MAXSIZE][MAXSIZE]{};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
        }
    }
    int dist[MAXSIZE][MAXSIZE]{};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i != j) dist[i][j] = INF;
        }
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    vector<int> perm;
    for (int i = 0; i < n; i++){
        if (i != start) perm.push_back(i); 
    }
    int ans = INF;
    do {
        int distSum = 0, curr = start;
        bool possible = true;
        for (int i = 0; i < perm.size(); i++){
            int next = perm[i];
            if (curr == next){
                possible = false;
                break;
            }
            distSum += dist[curr][next];
            curr = next;
        }
        if (possible) ans = min(distSum, ans);
    } while(next_permutation(perm.begin(), perm.end()));
    printf("%d\n", ans);
}