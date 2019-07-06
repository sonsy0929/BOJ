#include <cstdio>
#include <stack>
using namespace std;
int main(){
    int k;
    scanf("%d", &k);
    stack<int> stk;
    for (int i = 0; i < k; i++){
        int in;
        scanf("%d", &in);
        if (!in) stk.pop();
        else stk.push(in);
    }
    int ans = 0;
    while(!stk.empty()){
        ans += stk.top();
        stk.pop();
    }
    printf("%d", ans);
}