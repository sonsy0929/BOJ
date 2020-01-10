/*
The N cows in the herd (1 �� N �� 10,000) are conveniently numbered 1��N in the order in which they must appear in the dance.

�� ������ ����� �� �о Ʋ�� ���� ����...
�׷��� ������(x ~ x + N) �ҵ��� ���� ���� ��� �ϴµ�, �� �Է¿��� �־��� ������� �ҵ��� ���뿡 �����ؾ� �ϴµ�,
�׷��� ���� �ʰ� ���� �ߴ� �ð��� �� ����� ���� ���� ������ �ع����� �ФФ�..
�׷��� ������ ���ǿ� ���ϹǷ� Ʋ�ȴ� ����.. �� �κ� ����� ��ü���� ������ parameteric search�� ����� �����Ͽ���.. 
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