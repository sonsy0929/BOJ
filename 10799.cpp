#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string s;
    cin >> s;
    stack<char> stk;
    int ans = 0;
    char prev = s[0];
    for (auto c : s){
        if (c == '(') stk.push(c);
        else {
            stk.pop();
            if (prev == '(') ans += stk.size();
            else ans++;
        }
        prev = c;
    }
    cout << ans;
}