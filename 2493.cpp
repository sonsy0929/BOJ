#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
const int SIZE = 500'001;
int ans[SIZE];
int main(){
    int n;
    scanf("%d", &n);
    vector<p> v;
    v.push_back({0,0});
    for (int i = 1; i <= n; i++){
        int in;
        scanf("%d", &in);
        while (!v.empty() && v.back().first < in) {
            v.pop_back();
        }
        if (!v.empty()) ans[i] = v.back().second;
        v.push_back({in, i});
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}