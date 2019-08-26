#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string S, T;
    cin >> S >> T;
    bool possible = false;
    while (1){
        if (S.size() == T.size()){
            if (S == T) possible = true;
            break;
        }
        char c = T.back();
        T.pop_back();
        if (c == 'B') reverse(T.begin(), T.end()); 
    }
    cout << possible;
}