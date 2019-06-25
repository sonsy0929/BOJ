#include <cstdio>
#include <cstring>
using namespace std;
char S[10];
int N, _size, dp[10][10];
bool same(int s, int e){
    bool ret = true;
    char c = S[s];
    for (int i = s + 1; i < e; i++) ret &= c == S[i];
    return ret; 
}
int f(int s, int e){
    if (s == e) return 1;
    int &ret = dp[s][e];
    if (ret != -1) return ret;
    if (same(s, e)) return ret = 1;
    return ret = f(s + 1, e) + f(s, e - 1);
}
int main(){
    scanf("%s", S);
    _size = strlen(S);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(0, _size));
}