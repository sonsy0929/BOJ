/*
투 포인터
a^2 - b^2 = G인 a를 구하기
*/
#include <cstdio>
#include <vector>
using namespace std;
bool chk(int s, int e, int G){
    if (e == s+1 && e*e - s*s > G) return false;
    return true;
}
int main(){
    int G;
    scanf("%d", &G);
    int s = 1, e = 1;
    vector<int> ans;
    while (chk(s,e,G)){
        if (e*e-s*s == G){
            ans.push_back(e);
            s++, e++;
        }
        else if (e*e-s*s > G) s++;
        else e++;
    }
    if (ans.empty()) puts("-1");
    else for (int curr : ans) printf("%d\n", curr);
}