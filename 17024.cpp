/*
N개의 정점이 N - 1 개의 간선으로 연결된 것을 보고
트리의 구조임을 파악하는 것이 우선!
트리에서 정점 간의 거리가 2 이하인 경우는
dist 1 : parent ~ child
dist 2 : grand_parent ~ child, sibling
인 경우이다.
정점과 연결된 간선의 최대 개수를 D라 가정하면,
그 정점과 연결된 자식들은 D + 1개의 색으로 칠해야 한다.
(dist가 2인 경우 : sibling과 grand_parent ~ child의 색이 달라야 하고,
dist가 1인 경우 : parent ~ child의 색이 달라야 하므로)
따라서 각 정점마다 간선의 개수를 세어 최대값 D를 확인하고,
D + 1을 해준 것이 답이 된다.
 */
#include <cstdio>
#include <algorithm>
using namespace std;
int N, cnt[100'001];
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        cnt[u]++, cnt[v]++;
    }
    printf("%d\n", *max_element(cnt, cnt + N) + 1);
}