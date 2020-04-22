/*
idea : A + B == -(C + D)
stl�� hashmap�� unordered_map�� �������� ���� �����Ƿ�, pbds�� gp_hash_table�� �̿�����
https://codeforces.com/blog/entry/60737
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
int arr[5000][4];
int main() {
    fastio;
    __gnu_pbds::gp_hash_table<int, int> hash;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            hash[arr[i][0]+arr[j][1]]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += hash[-(arr[i][2]+arr[j][3])];
        }
    }
    cout << ans;
}