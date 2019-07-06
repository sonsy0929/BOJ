#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> p;
const int MAX = 1'000'001;
int idx[MAX];
int main(){
    int n;
    scanf("%d", &n);
    vector<p> v, stk;
    for (int i = 0; i < n; i++) {
        int in;
        scanf("%d", &in);
        v.push_back({in, i});
    }
    stk.push_back(v[0]);
    memset(idx, -1, sizeof(idx));
    for (int i = 1; i < n; i++) {
        while (!stk.empty() && stk.back().first < v[i].first){
            int it = stk.back().second;
            stk.pop_back();
            idx[it] = v[i].first;
        }
        stk.push_back(v[i]);
    }
    for (int i = 0; i < n; i++) printf("%d ", idx[v[i].second]);
}