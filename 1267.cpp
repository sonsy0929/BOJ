#include <cstdio>
using namespace std;
const int money[2] = {10, 15};
const int time[2] = {30, 60};
int main(){
    int N, t[20]{};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", t + i);
    int ans = 1e9, sum, k;
    bool same = false;
    for (int i = 0; i < 2; i++){
        sum = 0;
        for (int j = 0; j < N; j++){
            int d = t[j] / time[i];
            sum += (d + 1) * money[i];
        }
        if (ans >= sum) {
            if (ans == sum) same = true;
            ans = sum;
            k = i;
        }
    }
    if (same) printf("Y M %d", ans);
    else printf("%c %d\n", k ? 'M' : 'Y', ans);
}