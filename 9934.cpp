#include <cstdio>
#include <vector>
using namespace std;
int main(){
    int k, in;
    scanf("%d", &k);
    vector<int> v;
    for (int i = 0; i < (1 << k) - 1; i++){
        scanf("%d", &in);
        v.push_back(in);
    }
    vector<int> ans[10];
    bool used[1<<10]{};
    for (int i = 0; i < k; i++){
        bool flag = false;
        for (int j = 0; j < v.size(); j++){
            if (used[v[j]]) continue;
            if (!flag){
                ans[i].push_back(v[j]);
                used[v[j]] = true;
            }
            flag = !flag;
        }
    }
    for (int i = k - 1; i >= 0; i--){
        for (int curr : ans[i]) printf("%d ", curr);
        puts("");
    }
}