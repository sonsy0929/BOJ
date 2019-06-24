#include <iostream>
#include <string>
#include <stack>
#include <functional>
using namespace std;
function <double(double, double)> f[4] = {
    [](double a, double b) {return a + b;},
    [](double a, double b) {return a - b;},
    [](double a, double b) {return a * b;},
    [](double a, double b) {return a / b;}
};
char idx[128]; 
int main(){
    cout << fixed;
    cout.precision(2);
    int n, v[26];
    cin >> n;
    stack<double> stk;
    string s;
    cin >> s;
    idx['+'] = 0, idx['-'] = 1, idx['*'] = 2, idx['/'] = 3;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (auto c : s){
        int i = c - 'A';
        if (i >= 0 && i < 26) stk.push(v[i]);
        else {
            double b = stk.top();
            stk.pop();
            double a = stk.top();
            stk.pop();
            double ret = f[idx[c]](a, b);
            stk.push(ret);
        }
    }
    cout << stk.top();
}