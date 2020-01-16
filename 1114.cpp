/*
���� lower_bound�� �� �ʿ� ���� �� �����͸� �̿������� �Ǿ���.
������ ���� ����������� 'ó��' �ڸ��� ��ġ�� ���� ���� ����ϴ� �������µ�,
������ Ʋ�ȴ� ����� �볪���� �߶��� �� ���� �� ������ ������ ������ �� �� ���� ���� ���� ����ϴ� ������ ������ �����ߴ�.

ó�� �ڸ��� ��ġ�� ���� ���� ����ϴ� ����, ���� ��(��������)�������� ���� ����� ������ ���� ��츦 ã�ƾ� �Ѵ�.
�� �� ���������� ŭ�����ϰ� ������ ����(greedy), �������� �߸� ������ �ٸ� �����鿡 ���ؼ� ��������� ũ�Ⱑ ���� ���̴�.
��, ���� �������� ���� ����� ��찡 �ش�ǰ�,
�볪���� �ڸ� �� �ִ� Ƚ���� �� �����Ǹ� �������� �ڸ� ��ġ�� ����
Ƚ���� �����ִٸ� ���������� ���� ����� ��ġ�� ������ �ȴ�.

�ٽ� �� �� ������ �ؼ� '�׸���'�� ���� ��Ŀ� ���� �ٽ� �� �� ������ �غ���!
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int cutting[10010];
int L,K,C;
bool isPossible(int mid){
    int s = 0, e = 0, cnt = 0;
    while (e < K+2){
        int diff = cutting[e] - cutting[s];
        if (diff > mid && s+1 == e) return false;
        if (diff <= mid) e++;
        else{
            s = e-1;
            cnt++;
        }
    }
    return cnt <= C;
}
int main(){
    scanf("%d %d %d", &L,&K,&C);
    for (int i = 0; i < K; i++) scanf("%d", cutting+i);
    cutting[K] = 0;
    cutting[K+1] = L;
    sort(cutting, cutting+K+2);
    int lo = 0, hi = 1e9;
    while (lo+1 < hi){
        int mid = (lo+hi)/2;
        if (isPossible(mid)) hi = mid;
        else lo = mid;
    }
    int s = K+1, e = K+1, cnt = C;
    while (e >= 0){
        int diff = cutting[s] - cutting[e];
        if (diff <= hi) e--;
        else{
            s = e+1;
            if (--cnt == 0) break;
        }
    }
    printf("%d %d\n", hi, cnt ? cutting[1] : cutting[s]);
}