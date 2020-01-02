#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    for (int i = 2; ; i++){
        getline(cin, s);
        if (s == "Was it a cat I saw?") break;
        string ret;
        for (int j = 0; j < s.size(); j+=i){
            ret.push_back(s[j]);
        }
        cout << ret << "\n";
    }
}