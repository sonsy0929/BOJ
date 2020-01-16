/*
굳이 lower_bound를 쓸 필요 없이 투 포인터를 이용했으면 되었다.
가능한 것이 여러가지라면 '처음' 자르는 위치가 작은 것을 출력하는 문제였는데,
이전에 틀렸던 방식은 통나무를 잘랐을 때 가장 긴 길이의 조각이 나오는 것 중 가장 작은 것을 출력하는 식으로 문제를 오해했다.

처음 자르는 위치가 작은 것을 출력하는 경우는, 한쪽 끝(시작지점)에서부터 가장 가까운 지점을 고르는 경우를 찾아야 한다.
이 때 끝에서부터 큼지막하게 조각을 내면(greedy), 마지막에 잘린 조각은 다른 조각들에 비해서 상대적으로 크기가 작을 것이다.
즉, 시작 지점에서 가장 가까운 경우가 해당되고,
통나무를 자를 수 있는 횟수가 다 소진되면 마지막에 자른 위치가 정답
횟수가 남아있다면 시작점에서 가장 가까운 위치가 정답이 된다.

다시 한 번 복습을 해서 '그리디'의 접근 방식에 대해 다시 한 번 생각을 해보자!
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int cutting[10010];
int L,K,C;
bool isPossible(int mid){
    int s = 0, e = 0, cnt = 0;
    while (e < K+2){
        int diff = cutting[e] - cutting[s];
        if (diff > mid && s+1 == e) return false;
        if (diff <= mid) e++;
        else{
            s = e-1;
            cnt++;
        }
    }
    return cnt <= C;
}
int main(){
    scanf("%d %d %d", &L,&K,&C);
    for (int i = 0; i < K; i++) scanf("%d", cutting+i);
    cutting[K] = 0;
    cutting[K+1] = L;
    sort(cutting, cutting+K+2);
    int lo = 0, hi = 1e9;
    while (lo+1 < hi){
        int mid = (lo+hi)/2;
        if (isPossible(mid)) hi = mid;
        else lo = mid;
    }
    int s = K+1, e = K+1, cnt = C;
    while (e >= 0){
        int diff = cutting[s] - cutting[e];
        if (diff <= hi) e--;
        else{
            s = e+1;
            if (--cnt == 0) break;
        }
    }
    printf("%d %d\n", hi, cnt ? cutting[1] : cutting[s]);
}