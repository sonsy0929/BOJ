/*
�׳� ���� ����..
cmath�� �ִ� pow�� ���� double -> int�� ������ ĳ����(narrow conversion)�ؼ� �׷���
����� ���� ������ �ʾ���. �׷��� ���� _pow �Լ��� ������ ����
������ pow�Լ��� ����� �� ���� ������ ������ ���� �� ������ �׳� ���� �����ؼ� ����..
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using p = pair<int,int>;
int _pow(int a, int b){
    int ret = 1;
    for (int i = 0; i < b; i++) ret *= a;
    return ret; 
}
int main(){
    int n, k;
    cin >> n;
    vector<p> P;
    for (int i = 0; i < n; i++){
        cin >> k;
        P.push_back({k / 10, k % 10});
    }
    int ans = 0;
    for (auto pCurr : P){
        ans += _pow(pCurr.first, pCurr.second);
    }
    printf("%d\n", ans);
}