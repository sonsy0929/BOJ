#include <cstdio>
using namespace std;
int main(){
    int w,h,x,y,t;
    scanf("%d %d %d %d %d", &w, &h, &x, &y, &t);
    x += t, y += t;
    int D[2], R[2];
    D[0] = x / w; R[0] = x % w;
    D[1] = y / h; R[1] = y % h;
    if (D[0] & 1) x = w - R[0];
    else x = R[0];
    if (D[1] & 1) y = h - R[1];
    else y = R[1];
    printf("%d %d", x, y);
}