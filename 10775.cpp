/*
greedy, lower_bound

K번 항공기는 1 ~ K까지의 게이트에 도킹할 수 있다.
도킹하는 항공기가 최대가 되려면, 해당 항공기에 맞는 게이트에 먼저 도킹하고
만약 이미 도킹이 되어있다면, 1 ~ K-1의 게이트 중에서 가장 큰 K-1 게이트에 도킹하는 식으로
그리디하게 생각하면 도킹하는 항공기가 최대가 됨을 알 수 있다.
이를 set과 lower_bound를 통해 쉽게 구현할 수 있다. 
이 문제는 여러 풀이가 가능하다(union-find, segment tree 등)
segment tree로는 어떻게 하는지 상상도 안가는데 다시 한번 생각해봐야 할 문제..
*/
#include <cstdio>
#include <set>
using namespace std;
int main(){
    int G, P, g;
    scanf("%d %d", &G, &P);
    set<int> gates;
    for (int i = 1; i <= G; i++) gates.insert(i);
    int cnt = 0;
    for (int i = 0; i < P; i++){
        scanf("%d", &g);
        auto it = gates.lower_bound(g);
        if (*it == g){
            cnt++;
            gates.erase(it);
        }
        else{
            if (it == gates.begin()) break;
            gates.erase(--it);
            cnt++;
        }
    }
    printf("%d\n", cnt);
}