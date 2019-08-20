#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int SIZE = 1'000'001;
int v[SIZE], tracking[SIZE];
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", v + i);
    vector<int> lis;
    lis.push_back(v[0]);
    for (int i = 1; i < N; i++){
        if (lis.back() < v[i]) {
            lis.push_back(v[i]);
            tracking[i] = lis.size() - 1;
        }
        else {
            int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[idx] = v[i];
            tracking[i] = idx;
        }
    }
    printf("%d\n", lis.size());
    int top = lis.size() - 1;
    vector<int> ans;
    for (int i = N - 1; i >= 0; i--){
        if (tracking[i] == top){
            ans.push_back(v[i]);
            top--;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int curr : ans) printf("%d ", curr);
}