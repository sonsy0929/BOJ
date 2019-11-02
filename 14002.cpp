#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int MAXSIZE = 1000;
int POS[MAXSIZE], V[MAXSIZE], N;
vector<int> ans;
void backTrace(int idx, int num){
    if (idx < 0) return;
    if (POS[idx] == num){
        backTrace(idx - 1, num - 1);
        ans.push_back(V[idx]);
    }
    else backTrace(idx - 1, num);
}
int main(){
    scanf("%d", &N);
    vector<int> LIS(1, 0);
    for (int i = 0; i < N; i++){
        scanf("%d", V+i);
        if (LIS.back() < V[i]) LIS.push_back(V[i]);
        else *lower_bound(LIS.begin(), LIS.end(), V[i]) = V[i];
        POS[i] = distance(LIS.begin(), lower_bound(LIS.begin(), LIS.end(), V[i]));
    }
    backTrace(N-1, LIS.size()-1);
    printf("%d\n", LIS.size()-1);
    for (int &i : ans) printf("%d ", i);
}