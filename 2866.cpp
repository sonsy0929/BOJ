#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int R, C;
vector<string> sv;
bool isPossible(int pos){
    set<string> st;
    for (int j = 0; j < C; j++){
        string s;
        for (int i = pos; i < R; i++){
            s.push_back(sv[i][j]);
        }
        if (st.count(s)) return false;
        st.insert(s);
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    for (int i = 0; i < R; i++){
        string s;
        cin >> s;
        sv.push_back(s);
    }
    int lo = 0, hi = R;
    while (lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if (!isPossible(mid)) hi = mid;
        else lo = mid;
    }
    cout << lo << "\n";
}