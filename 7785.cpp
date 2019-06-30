#include <iostream>
#include <set>
#include <functional>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string name, cmd;
    set<string, greater<string>> st;
    for (int i = 0; i < n; i++){
        cin >> name >> cmd;
        if (cmd == "enter") st.insert(name);
        else st.erase(name);
    }
    for (auto it : st) cout << it << '\n';
}