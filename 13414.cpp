#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
set<string> used;
set<int> st;
vector<string> v;
int main(){
    int K, L;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K >> L;
    string in;
    for (int i = 0; i < L; i++){
        cin >> in;
        v.push_back(in);
    }
    for (int i = L - 1; i >= 0; i--){
        if (used.count(v[i])) continue;
        used.insert(v[i]);
        st.insert(i);
    }
    for (auto i : st){
        if (!K) break;
        cout << v[i] << "\n";
        K--;
    }
}