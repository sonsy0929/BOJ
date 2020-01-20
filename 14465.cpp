/*
슬라이딩 윈도우 혹은 Prefix Sum으로 풀 수 있는 문제
이 문제는 슬라이딩 윈도우 방식으로 풀었다!
구간을 가지고 빠르게 해결을 하려고 할 때 Prefix Sum이 유용하게 사용되는 것 같다.
세그먼트 트리는 구간 내의 원소를 업데이트 할 경우에 사용되지만, 업데이트가 없다면 Prefix Sum을 사용해서
빠르게 해결할 수 있는 것을 여러 문제를 통해 확인을 할 수 있었다. 
*/
#include <cstdio>
#include <algorithm>
using namespace std;
bool isBroken[100'010];
int main(){
    int N,K,B;
    scanf("%d %d %d", &N,&K,&B);
    for (int i = 0; i < B; i++){
        int in;
        scanf("%d", &in);
        isBroken[in] = true;
    }
    int cnt = 0, ans = 1e9;
    for (int i = 1; i <= K; i++) cnt += isBroken[i];
    for (int i = K+1; i <= N; i++){
        if (isBroken[i]) cnt++;
        if (isBroken[i-K]) cnt--;
        ans = min(ans,cnt);
    }
    printf("%d\n",ans);
}