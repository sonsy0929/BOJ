/*
그냥 구현 문제..
cmath에 있는 pow를 쓰면 double -> int로 강제로 캐스팅(narrow conversion)해서 그런지
제대로 값이 나오지 않았음. 그래서 직접 _pow 함수를 구현함 ㅎㅎ
앞으로 pow함수를 써야할 때 오차 때문에 문제가 생길 수 있으니 그냥 직접 구현해서 쓰자..
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