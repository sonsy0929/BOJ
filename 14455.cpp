/*
���� ������ �� �˰� ����� �躸�� 4������ ���� ����..
���� ������ ������ �ؼ��� �߸��ϰ�, ȥ�ڸ��� �������� Ǭ �����̴�..
�ߺ��� ���ִ� ��ũ������ map�� �̿��ؼ� �Ƹ���� ���ϴ� �����
green55�� ����̴�. �� ������ �ٷ� ���� �Ẹ�Ҵ�.
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