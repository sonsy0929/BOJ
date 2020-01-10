/*
쉬운 문제인 줄 알고 상당히 얕보다 4번만에 맞춘 문제..
쉬운 문제는 맞으나 해석을 잘못하고, 혼자만의 착각에서 푼 문제이다..
중복을 없애는 테크닉으로 map을 이용해서 아름답게 구하는 방법은
green55님 방법이다. 넘 멋져서 바로 따라 써보았다.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using p = pair<int,string>;
string cows[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
int main(){
    int N;
    cin >> N;
    map<string, int> mp;
    for (int i = 0; i < 7; i++){
        mp[cows[i]] = 0;
    }
    for (int i = 0; i < N; i++){
        string s; int k;
        cin >> s >> k;
        mp[s] += k;
    }
    map<int, vector<string>> result;
    for (auto it : mp){
        int i = it.second;
        result[i].push_back(it.first);
    }
    if (result.size() < 2){
        cout << "Tie\n";
        return 0;
    }
    auto it = result.begin();
    it++;
    if (it->second.size() > 1) cout << "Tie\n";
    else cout << it->second.front() << "\n";
}