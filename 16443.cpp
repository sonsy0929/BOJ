#include <cstdio>
using namespace std;
int n, r, c;
int main(){
    scanf("%d %d %d", &n, &r, &c);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("%c", (r + c) % 2 == (i + j) % 2 ? 'v' : '.');
        }
        puts("");
    }
}