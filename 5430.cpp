#include <iostream>
#include <sstream>
#include <string>
#include <deque>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        string cmd, in;
        cin >> cmd >> n >> in;
        deque<int> dq;
        stringstream ss(in);
        char c; int val;
        while (ss >> c >> val) dq.push_back(val);
        bool Reverse = false;
        bool possible = true;
        for (auto c : cmd){
            if (c == 'R') {
                Reverse = !Reverse;
                continue;
            }
            if (c == 'D' && dq.empty()) {
                possible = false;
                break;
            }
            if (Reverse) dq.pop_back();
            else dq.pop_front();
        }
        if (!possible) cout << "error" << '\n';
        else{
            cout << '[';
            if (Reverse) {
                for (int i = dq.size() - 1; i >= 0; i--){
                    cout << dq[i];
                    if (i != 0) cout << ','; 
                }
            }
            else {
                for (int i = 0; i < dq.size(); i++){
                    cout << dq[i];
                    if (i != dq.size() - 1) cout << ',';
                }
            }
            cout << ']' << '\n';
        }
    }
}