#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    if (n > 5) {
        int one = n - 1, five = n - 5;
        if (one % 8 > five % 8) printf("%d", 5 - (five % 8));
        else printf("%d", 1 + (one % 8));
    }
    else printf("%d\n", n);
}