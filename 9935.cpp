#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s, bomb;
    cin >> s >> bomb;
    vector<char> v;
    int len = bomb.size();
    for (int i = 0; i < s.size(); i++){
        v.push_back(s[i]);
        int flag = 0;
        vector<char> tmp;
        if (v.back() == bomb.back()){
            int r = len - 1;
            for (; !v.empty() && v.back() == bomb[r]; r--, v.pop_back()) {
                flag++;
                tmp.push_back(v.back());
            }
        }
        if (flag && flag != len) {
            reverse(tmp.begin(), tmp.end());
            for (auto c : tmp) v.push_back(c);
        }
    }
    if (v.empty()) cout << "FRULA";
    else for (auto c : v) cout << c;
}