#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, S;
    scanf("%d", &N);
    vector<int> v(N, 0);
    for (int i = 0; i < N; i++) scanf("%d", &v[i]);
    scanf("%d", &S);
    for (int i = 0; i < N; i++){
        if(!S) break;
        auto bound = min(v.begin() + i + S + 1, v.end());
        auto maxIt = max_element(v.begin() + i, bound);
        for (auto it = maxIt; it > v.begin() + i; it--) swap(*it, *(it-1));
        S -= maxIt - (v.begin() + i);
    }
    for (int &i : v) printf("%d ", i);
}