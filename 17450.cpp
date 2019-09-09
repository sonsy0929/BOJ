#include <cstdio>
using namespace std;
int main(){
    int P[3], W[3];
    for (int i = 0; i < 3; i++) scanf("%d %d", &P[i], &W[i]);
    double mx = 0;
    int num = 0;
    char C[3] = {'S', 'N', 'U'};
    for (int i = 0; i < 3; i++){
        double p = P[i] * 10;
        if (p >= 5000) p -= 500;
        double k = (W[i] * 10) / p;
        if (mx < k){
            mx = k;
            num = i;
        }
    }
    printf("%c", C[num]);
}