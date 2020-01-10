/*
greedy, lower_bound

K�� �װ���� 1 ~ K������ ����Ʈ�� ��ŷ�� �� �ִ�.
��ŷ�ϴ� �װ��Ⱑ �ִ밡 �Ƿ���, �ش� �װ��⿡ �´� ����Ʈ�� ���� ��ŷ�ϰ�
���� �̹� ��ŷ�� �Ǿ��ִٸ�, 1 ~ K-1�� ����Ʈ �߿��� ���� ū K-1 ����Ʈ�� ��ŷ�ϴ� ������
�׸����ϰ� �����ϸ� ��ŷ�ϴ� �װ��Ⱑ �ִ밡 ���� �� �� �ִ�.
�̸� set�� lower_bound�� ���� ���� ������ �� �ִ�. 
�� ������ ���� Ǯ�̰� �����ϴ�(union-find, segment tree ��)
segment tree�δ� ��� �ϴ��� ��� �Ȱ��µ� �ٽ� �ѹ� �����غ��� �� ����..
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