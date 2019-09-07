#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int idx[128], ca[51][4];
char i2c[4] = {'A', 'C', 'G', 'T'};
int main(){
    int n, m;
    cin >> n >> m;
    string s;
    vector<string> DNA;
    for (int i = 0; i < n; i++){
        cin >> s;
        DNA.push_back(s);
    }
    idx['A'] = 0, idx['C'] = 1, idx['G'] = 2, idx['T'] = 3;
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            char c = DNA[i][j];
            ca[j][idx[c]]++;
        }
    }
    string ans;
    int ansVal = 0;
    for (int i = 0; i < m; i++){
        int mx = 0;
        char c;
        for (int j = 0; j < 4; j++){
            if (mx < ca[i][j]){
                mx = ca[i][j];
                c = i2c[j];
            }
        }
        ansVal += n - mx;
        ans.push_back(c);
    }
    cout << ans << "\n" << ansVal;
}