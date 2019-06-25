#include <iostream>
#include <string>
#include <set>
using namespace std;
int _size;
bool used[10];
string s;
set<string> st;
void f(int pos, int l, int r, string data, string track){
    if (pos == _size) {
        if (data != s) return;
        st.insert(track + data);
        return;
    }
    if (l - 1 >= 0 && !used[l - 1]) {
        used[l - 1] = true;
        string tmp;
        tmp.push_back(s[l - 1]);
        f(pos + 1, l - 1, r, tmp + data, track + tmp + data);
        used[l - 1] = false;
    }
    if (r + 1 < _size && !used[r + 1]) {
        used[r + 1] = true;
        string tmp;
        tmp.push_back(s[r + 1]);
        f(pos + 1, l, r + 1, data + tmp, track + data + tmp);
        used[r + 1] = false;
    }
}
int main(){
    cin >> s;
    _size = s.size();
    for (int i = 0; i < _size; i++){
        used[i] = true;
        string tmp;
        tmp.push_back(s[i]);
        f(1, i, i, tmp, tmp);
        used[i] = false;
    }
    cout << st.size() << "\n";
}