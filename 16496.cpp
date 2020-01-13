/*
greedy
두 string을 더 했을 때, u + v > v + u 순으로 정렬되도록 하면 큰 수가 나온다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    vector<string> v;
    cin >> N;
    for (int i = 0; i < N; i++){
        string in;
        cin >> in;
        v.push_back(in);
    }
    sort(v.begin(), v.end(), [](const string &u, const string &v){
        return u + v > v + u;
    });
    if (v.front() == "0") cout << "0";
    else for (auto s : v) cout << s;
}