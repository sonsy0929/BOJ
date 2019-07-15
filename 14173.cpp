#include <cstdio>
#include <algorithm>
using namespace std;
struct Rect{
    int x1, y1, x2, y2;
};
int main(){
    Rect R[2];
    for (int i = 0; i < 2; i++){
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        R[i] = {x1, y1, x2, y2};
    }
    int min_r = min(R[0].y1, R[1].y1);
    int max_r = max(R[0].y2, R[1].y2);
    int min_c = min(R[0].x1, R[1].x1);
    int max_c = max(R[0].x2, R[1].x2);
    int ret = max(max_r - min_r, max_c - min_c);
    printf("%d\n", ret * ret);
}
