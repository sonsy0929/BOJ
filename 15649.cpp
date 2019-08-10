#include <cstdio>
#include <vector>
using namespace std;
int n, m;
vector<int> perm;
bool used[8];
void f(int pos, int cnt){
    if (cnt == m){
        for (int curr : perm) printf("%d ", curr);
        puts("");
        return;
    } 
    for (int i = 0; i < n; i++){
        if (used[i]) continue;
        used[i] = true;
        perm.push_back(i + 1);
        f (i + 1, cnt + 1);
        used[i] = false;
        perm.pop_back();
    }
}
int main(){
    scanf("%d %d", &n, &m);
    f(0, 0);
}