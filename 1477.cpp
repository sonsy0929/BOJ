#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, L;
vector<int> v;
bool isPossible(int m){
    int cnt = 0;
    for (int i = 0; i < v.size() - 1; i++){
        int diff = v[i + 1] - 1 - v[i];
        cnt += diff / m;
    }
    return cnt > M;
}
int main(){
    scanf("%d %d %d", &N, &M, &L);
    for (int i = 0; i < N; i++){
        int in;
        scanf("%d", &in);
        v.push_back(in);
    }
    v.push_back(0), v.push_back(L);
    sort(v.begin(), v.end());
    int lo = 0, hi = L;
    while (lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if (isPossible(mid)) lo = mid;
        else hi = mid;
    }
    printf("%d\n", hi);
}