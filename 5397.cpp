#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string in;
        cin >> in;
        vector<char> v, tmp;
        for (auto c : in){
            if (c == '<') {
                if (v.empty()) continue;
                tmp.push_back(v.back());
                v.pop_back();
            }
            else if (c == '>') {
                if (tmp.empty()) continue;
                v.push_back(tmp.back());
                tmp.pop_back();
            }
            else if (c == '-') {
                if (v.empty()) continue;
                v.pop_back();
            }
            else v.push_back(c);
        }
        while(!tmp.empty()) {
            v.push_back(tmp.back());
            tmp.pop_back();
        }
        for (auto c : v) cout << c;
        cout << '\n';
    }
}