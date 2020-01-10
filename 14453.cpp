/*
i번째 선택부터 무엇을 낼지 바꾼다고 하자.
그러면, 1번째 ~ i번째 / i+1번째 ~ n번째 게임으로 나눈다.
예전 codeforce div3 문제 중
왼쪽에서 오른쪽으로 진행하는 prefix Sum과
오른쪽에서 왼쪽으로 진행하는 prefix Sum을 이용해서
max(ans, L[i] + R[i+1])와 같은 꼴을 통해 최대값을 구하는 것을 배울 수 있었다.
이와 비슷한 방법을 이용하여,
L[i][k]는 1번째부터 i번째 까지 k를 내서 이긴 최대 횟수이고,
R[i][k]는 N번째부터 i번째 까지 k를 내서 이긴 최대 횟수이다.
이제 이를 이용하여 각각의 경우에서 최대값을 구하면 된다.

아니면, 각 세트에서 상대가 가장 많이 내는 것을 이기는 것을 내는 것이 당연히 최적임을 알 수 있다.
부분합을 이용해서 상대가 특정 연속된 게임에서 가장 많이 내는지 쉽게 구할 수 있으므로
이를 통해서 답을 구할 수도 있다.
*/

#include <cstdio>
#include <algorithm>
using namespace std;
constexpr int MAX = 100'009;
int L[MAX][3], R[MAX][3];
char HPS[MAX];
char S[3] = {'H','P','S'};
bool chk(char u, char v){
    if (u == 'H' && v == 'S') return true;
    if (u == 'P' && v == 'H') return true;
    if (u == 'S' && v == 'P') return true;
    return false;
}
int main(){
    int N; 
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf(" %c", HPS+i);
    for (int i = 0; i < 3; i++){
        for (int j = 1; j <= N; j++){
            if (chk(S[i], HPS[j])){
                L[j][i] = L[j-1][i] + 1;
            }
            else L[j][i] = max(L[j][i], L[j-1][i]);
        }
        for (int j = N; j >= 1; j--){
            if (chk(S[i], HPS[j])){
                R[j][i] = R[j+1][i] + 1; 
            }
            else R[j][i] = max(R[j][i], R[j+1][i]);
        }
    }
    int ans = 0;
    for (int j = 1; j <= N; j++){
        ans = max({ans, L[j][0] + R[j+1][1], L[j][0] + R[j+1][2]});
        ans = max({ans, L[j][1] + R[j+1][2], L[j][1] + R[j+1][0]});
        ans = max({ans, L[j][2] + R[j+1][1], L[j][2] + R[j+1][0]});
    }
    printf("%d\n", ans);
}