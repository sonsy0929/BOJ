#include <iostream>
#include <string>
using namespace std;
int main(){
    string s, end = "Was it a cat I saw?";
    for (int i = 2; ; i++){
        cin >> s;
        if (s == end) break;
        string ret;
        for (int j = 0; j < s.size(); j+=i){
            ret.push_back(s[j]);
        }
        cout << ret << "\n";
    }
}