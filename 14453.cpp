/*
i��° ���ú��� ������ ���� �ٲ۴ٰ� ����.
�׷���, 1��° ~ i��° / i+1��° ~ n��° �������� ������.
���� codeforce div3 ���� ��
���ʿ��� ���������� �����ϴ� prefix Sum��
�����ʿ��� �������� �����ϴ� prefix Sum�� �̿��ؼ�
max(ans, L[i] + R[i+1])�� ���� ���� ���� �ִ밪�� ���ϴ� ���� ��� �� �־���.
�̿� ����� ����� �̿��Ͽ�,
L[i][k]�� 1��°���� i��° ���� k�� ���� �̱� �ִ� Ƚ���̰�,
R[i][k]�� N��°���� i��° ���� k�� ���� �̱� �ִ� Ƚ���̴�.
���� �̸� �̿��Ͽ� ������ ��쿡�� �ִ밪�� ���ϸ� �ȴ�.

�ƴϸ�, �� ��Ʈ���� ��밡 ���� ���� ���� ���� �̱�� ���� ���� ���� �翬�� �������� �� �� �ִ�.
�κ����� �̿��ؼ� ��밡 Ư�� ���ӵ� ���ӿ��� ���� ���� ������ ���� ���� �� �����Ƿ�
�̸� ���ؼ� ���� ���� ���� �ִ�.
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