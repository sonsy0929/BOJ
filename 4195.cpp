#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int SIZE = 200'001;
int uf[SIZE];
int find(int n){
    if (uf[n] < 0) return n;
    return uf[n] = find(uf[n]);
}
void merge(int u, int v){
    u = find(u);
    v = find(v);
    uf[v] += uf[u];
    uf[u] = v;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int F, p = 0;
        cin >> F;
        map<string, int> mp;
        fill(uf, uf + SIZE, -1);
        string s1, s2;
        for (int i = 1; i <= F; i++){
            cin >> s1 >> s2;
            if (!mp.count(s1)) mp[s1] = p++;
            if (!mp.count(s2)) mp[s2] = p++;
            merge(mp[s1], mp[s2]);
            cout << -uf[find(mp[s1])] << "\n";
        }
    }
}