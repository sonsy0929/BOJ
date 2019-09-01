#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ll N;
    scanf("%lld", &N);
    if (N >= 5) puts("Love is open door");
    else{
        int curr;
        scanf("%d", &curr);
        for (int i = 0; i < N-1; i++){
            curr = !curr;
            printf("%d\n", curr);
        }
    }
}