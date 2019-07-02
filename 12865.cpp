/*
Knapsack ����!
dp[i] = ������ �ִ� ���� ���԰� i�� �� ���� �� �ִ� �ִ밪
i��� �ε������� ���� ���ŵ��� ����, dp[j - w[i]]�� ���� Ȯ���Ѵٴ� ����,
2���� �迭���� dp[i - 1][j - w[i]]�� ���� �Ͱ� ����.
�׷���, j���� w[i] ~ K(�ִ� ����)���� ������������ ����,
dp[j - w[i]]���� 2�������� ���� ��, dp[i][j - 2 * w[i]] + v[i]�� �� �ִ�.
�̴� item�� �ߺ��ؼ� ������ ����ϴ� ���!! (�� ���������� �ߺ��� �߻��ؼ��� �ȵ�!!)
*/

#include <cstdio>
#include <algorithm>
using namespace std;
int dp[100001], w[100], v[100];
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d %d", w + i, v + i);
    for (int i = 0; i < n; i++){
        for (int j = k; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    printf("%d\n", dp[k]);
}