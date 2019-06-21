#include <cstdio>
#include <stack>
using namespace std;
int main(){
    int n, p;
    scanf("%d %d", &n, &p);
    stack<int> stk[7];
    for (int i = 1; i < 7; i++) stk[i].emplace(0);
    int ans = 0;
    for (int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        auto &ref = stk[a];
        while (ref.top() > b){
            ans++;
            ref.pop();
        }
        if (ref.top() < b){
            ans++;
            ref.emplace(b);
        }
    }
    printf("%d\n", ans);
}