#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int A, B;
    scanf("%d %d", &A, &B);
    vector<int> va(A, 0), vb(B, 0), ans;
    for (int i = 0; i < A; i++) scanf("%d", &va[i]);
    for (int i = 0; i < B; i++) scanf("%d", &vb[i]);
    sort(vb.begin(), vb.end());
    for (int curr : va){
        if (!binary_search(vb.begin(), vb.end(), curr)){
            ans.push_back(curr);
        }
    }
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for (int curr : ans) printf("%d ", curr);
}