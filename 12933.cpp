#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int quack[5], idx[128];
char in[2501];
bool isPossible(){
    for (int i = 0; i < 4; i++){
        if (quack[i] < quack[i + 1]) return false;
    }
    return true;
}
int main(){
    scanf("%s", in);
    int L = strlen(in);
    int ans = 0;
    bool possible = true;
    idx['q'] = 0, idx['u'] = 1, idx['a'] = 2, idx['c'] = 3, idx['k'] = 4;
    for (int i = 0; i < L; i++){
        quack[idx[in[i]]]++;
        if (!isPossible()){
            possible = false;
            break;
        }
        ans = max(ans, *max_element(quack, quack + 5));
        if (*min_element(quack, quack + 5) == 1){
            for (int i = 0; i < 5; i++) quack[i]--;
        }
    }
    for (int i = 0; i < 5; i++){
        if (quack[i]) possible = false;
    }
    if (!(L % 5) && possible) printf("%d\n", ans);
    else puts("-1");
}