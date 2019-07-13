/*
N���� ������ N - 1 ���� �������� ����� ���� ����
Ʈ���� �������� �ľ��ϴ� ���� �켱!
Ʈ������ ���� ���� �Ÿ��� 2 ������ ����
dist 1 : parent ~ child
dist 2 : grand_parent ~ child, sibling
�� ����̴�.
������ ����� ������ �ִ� ������ D�� �����ϸ�,
�� ������ ����� �ڽĵ��� D + 1���� ������ ĥ�ؾ� �Ѵ�.
(dist�� 2�� ��� : sibling�� grand_parent ~ child�� ���� �޶�� �ϰ�,
dist�� 1�� ��� : parent ~ child�� ���� �޶�� �ϹǷ�)
���� �� �������� ������ ������ ���� �ִ밪 D�� Ȯ���ϰ�,
D + 1�� ���� ���� ���� �ȴ�.
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