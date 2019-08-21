#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
int getMiddle(int n){
    int ret = 0;
    n /= 10;
    for (int i = 0; n && i < 2; n /= 10, i++){
        ret += (n % 10) * pow(10, i);
    }
    return ret;
}
int main(){
    int N;
    scanf("%d", &N);
    set<int> st;
    int curr = N, cnt = 0;
    while (!st.count(curr)){
        st.insert(curr);
        int mid = getMiddle(curr);
        curr = pow(mid, 2);
        cnt++;
    }
    printf("%d\n", cnt);
}