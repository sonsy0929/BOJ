/*
�ＺSDS �԰��׽�Ʈ ��������? �̶� ����� ���� ����
�켱���� ť�� Ȱ���ϴ� ��ǥ���� ����
��ġ�� ū ������ ���� ������ �����ϴ� ���濡 �־�� �̵�
'������ ���� <=���濡 ���� �� �ִ� �ִ빫��'�� �����ϴ� ���� �� ��ġ�� ���� ū ��
������ ������ �������� ���� ������ �����ؼ�, ������ ������ ���� �� �� �߿��� ������ ��ġ�� ���� ū ���� �����ؾ� �Ѵ�.
[ ~ ���濡 ���� �� �ִ� �ִ� ����]�� �����ϴ� ���� �� �ִ� ��ġ�� ���� ������ ���Ϸ���
������ ��ġ�� �켱����ť(�ִ���)�� push�ؼ� ���� ���� ������ �����ؾ� �Ѵ�.
*/
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> p;
const int BAG = 1'000'001;
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<p> info;
    for (int i = 0; i < n + k; i++){
        int u, v;
        if (i < n) {
            scanf("%d %d", &u, &v);
            info.push_back({u, v});
        }
        else {
            scanf("%d", &u);
            info.push_back({u, BAG});
        }
    }
    sort(info.begin(), info.end());
    priority_queue<int> pq;
    long long ans = 0;
    for (auto it : info){
        if (it.second != BAG) pq.push(it.second);
        else {
            if (!pq.empty()) {
                ans += pq.top();
                pq.pop();
            }
        }
    }
    printf("%lld\n", ans);
}