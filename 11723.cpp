#include <iostream>
#include <set>
using namespace std;
int M;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M;
    string in;
    int val;
    set<int> st;
    for (int i = 0; i < M; i++){
        cin >> in;
        if (in == "add") {
            cin >> val;
            st.insert(val);
        }
        if (in == "check") {
            cin >> val;
            cout << st.count(val) << "\n";
        }
        if (in == "remove") {
            cin >> val;
            st.erase(val);
        }
        if (in == "toggle") {
            cin >> val;
            if (st.count(val)) st.erase(val);
            else st.insert(val);
        }
        if (in == "all") {
            for (int k = 1; k <= 20; k++) st.insert(k);
        }
        if (in == "empty") st.clear();
    }
}