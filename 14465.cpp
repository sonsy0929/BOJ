/*
�����̵� ������ Ȥ�� Prefix Sum���� Ǯ �� �ִ� ����
�� ������ �����̵� ������ ������� Ǯ����!
������ ������ ������ �ذ��� �Ϸ��� �� �� Prefix Sum�� �����ϰ� ���Ǵ� �� ����.
���׸�Ʈ Ʈ���� ���� ���� ���Ҹ� ������Ʈ �� ��쿡 ��������, ������Ʈ�� ���ٸ� Prefix Sum�� ����ؼ�
������ �ذ��� �� �ִ� ���� ���� ������ ���� Ȯ���� �� �� �־���. 
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