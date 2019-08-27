#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
bool Elsie[100'000];
int main(){
    int N;
    scanf("%d", &N);
    vector<int> E;
    set<int> B;
    for (int i = 0; i < N; i++){
        int in;
        scanf("%d", &in);
        Elsie[in-1] = true;
        E.push_back(in-1);
    }
    for (int i = 0; i < 2 * N; i++){
        if (Elsie[i]) continue;
        B.insert(i);
    }
    int ans = 0;
    for (int curr : E){
        auto iter = B.upper_bound(curr);
        if (iter != B.end()){
            B.erase(*iter);
            ans++;
        }
    }
    printf("%d\n", ans);
}