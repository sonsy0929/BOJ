#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string s;
    cin >> s;
    stack<char> stk;
    for (auto c : s){
        if (c == '(') stk.push(c);
        else if (c == ')') {
            while (!stk.empty() && stk.top() != '('){
                cout << stk.top();
                stk.pop();
            }
            if (!stk.empty()) stk.pop();
        }
        else if (c == '+' || c == '-'){
            while (!stk.empty() && stk.top() != '(') {
                cout << stk.top();
                stk.pop();
            }
            stk.push(c);
        }
        else if (c == '*' || c == '/'){
            while (!stk.empty() && stk.top() != '('
            && stk.top() != '+' && stk.top() != '-') {
                cout << stk.top();
                stk.pop();
            }
            stk.push(c);
        }
        else cout << c;
    }
    while(!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
}