#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    stack<int> stk;
    vector<char> v;
    stk.push(0);
    bool possible = true;
    int k = 1;
    for (int i = 0; i < n; i++){
        int val;
        scanf("%d", &val);
        if (stk.top() > val) possible = false;
        while (k <= val) {
            stk.push(k++);
            v.push_back('+');
        }
        stk.pop();
        v.push_back('-');
    }
    if (possible) {
        for (auto c : v) printf("%c\n", c);
    }
    else puts("NO");
}