#include <cstdio>
using namespace std;
int main(){
    int n, money[] = {500, 100, 50, 10, 5, 1};
    scanf("%d", &n);
    int k = 1000 - n, ans = 0;
    for (int i = 0; i < 6; i++){
        if (k / money[i] == 0) continue;
        ans += k / money[i];
        k %= money[i];
    }
    printf("%d\n",ans);
}