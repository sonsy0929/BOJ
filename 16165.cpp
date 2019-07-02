#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int idx[100];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<string, int> gHash;
    map<string, string> mTog;
    vector<string> girlGroup[100];
    int p = 0;
    string in;
    for (int i = 0; i < n; i++){
        string gName; int val;
        cin >> gName >> val;
        gHash[gName] = p++;
        for (int j = 0; j < val; j++){
            cin >> in;
            mTog[in] = gName;
            girlGroup[p - 1].push_back(in);
        }
    }
    for (int i = 0; i < p; i++) sort(girlGroup[i].begin(), girlGroup[i].end());
    for (int i = 0; i < m; i++){
        int q;
        cin >> in >> q;
        if (q) cout << mTog[in] << "\n";
        else {
            int idx = gHash[in];
            for (auto s : girlGroup[idx]) cout << s << "\n";
        }
    }
}