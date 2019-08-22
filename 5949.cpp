#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string s, ans;
    cin >> s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++){
        if (i && i % 3 == 0) ans.push_back(',');
        ans.push_back(s[i]);
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}