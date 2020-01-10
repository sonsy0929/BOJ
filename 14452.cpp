/*
The N cows in the herd (1 ≤ N ≤ 10,000) are conveniently numbered 1…N in the order in which they must appear in the dance.

이 문구를 제대로 안 읽어서 틀린 문제 ㅎㅎ...
그룹이 지어진(x ~ x + N) 소들은 같이 춤을 춰야 하는데, 즉 입력에서 주어진 순서대로 소들이 무대에 입장해야 하는데,
그렇게 하지 않고 춤을 추는 시간이 긴 얘들을 먼저 오게 정렬을 해버렸음 ㅠㅠㅠ..
그러면 문제의 조건에 반하므로 틀렸던 문제.. 이 부분 말고는 전체적인 로직은 parameteric search로 제대로 구현하였음.. 
*/

#include <cstdio>
#include <functional>
#include <queue>
#include <algorithm>
using namespace std;
constexpr int MAX = 100'000;
int N, K, D[MAX];
bool isPossible(int mid){
    if (mid >= N) return true;
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0, top;
    for (; i < mid; i++) pq.push(D[i]);
    for (i = mid; i < N; i++){
        top = pq.top();
        pq.pop();
        pq.push(top + D[i]);
    }
    for (; !pq.empty(); top = pq.top(), pq.pop());
    return top <= K;
}
int main(){
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", D+i);
    int lo = 0, hi = MAX;
    while (lo + 1 < hi){
        int mid = (lo+hi)/2;
        if (isPossible(mid)) hi = mid;
        else lo = mid;
    }
    printf("%d\n", hi);
}