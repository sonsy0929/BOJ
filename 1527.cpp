#include <cstdio>
#include <cmath>
using namespace std;
int a, b, cnt;
void f(int pos, int param){
    if (pos > 9) return;
    if (a <= param && param <= b) cnt++;
    f(pos + 1, param * 10 + 4);
    f(pos + 1, param * 10 + 7);
}
int main(){
    scanf("%d %d", &a, &b);
    f(0, 0);
    printf("%d\n", cnt);
}