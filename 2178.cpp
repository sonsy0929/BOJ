#include <cstdio>
#include <queue>
using namespace std;

const int roff[4] = { -1, 1, 0, 0 };
const int coff[4] = { 0, 0, -1, 1 };

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	bool map[100][100];
	for (int i = 0; i<N; i++)
		for (int j = 0; j<M; j++)
			scanf("%1d", &map[i][j]);

	// visited �迭: false�� ���� ���� �̵��Ѵ�.
	bool visited[100][100] = { 0 };
	visited[0][0] = true;
	// ����� ť. �̶� �� ���¸� "��*100+��"�� �ؽð����� ���
	queue<int> Q;
	Q.push(0);
	// �̵� Ƚ��
	int result = 1;

	/*
	���� while���� ť�� ��� ���� ���� ���ȸ� ������ ������
	�� ������ ��� �׻� ���� ������ ��츸 �־����Ƿ� �׷� �ʿ� ����.
	���� �����ϱ� ���� ť�� ��� �ȴٸ�, ������ �� ���� ����.
	*/
	while (1) {
		// ���� ť�� ���� ������ŭ ���� for���� ����
		int qSize = Q.size();
		for (int i = 0; i<qSize; i++) {
			// �ؽð����κ��� ���� ��ġ�� ��, �� ��ȣ�� ������
			int r = Q.front() / 100;
			int c = Q.front() % 100;
			Q.pop();
			// ������ ���, �̵� Ƚ�� ����ϰ� ���α׷� ����
			if (r == N - 1 && c == M - 1) {
				printf("%d\n", result);
				return 0;
			}

			/*
			�� ���⸶�� ������ �ڵ��� �� ���� ������
			offset �迭�� �� ���⸶���� ��, �� �̵� �Ÿ��� ����ϸ�
			for���� 4�� ������ �ڵ��ϴ� �͵� �����ϴ�.
			*/
			for (int d = 0; d<4; d++) {
				// �̵��� ���� ��ġ
				int nr = r + roff[d];
				int nc = c + coff[d];
				// �̷� �ٱ����δ� �̵� �Ұ���
				if (nr<0 || nr >= N || nc<0 || nc >= M) continue;
				// ���̸� �湮 �Ұ���
				if (!map[nr][nc]) continue;
				// �̹� �湮�� ��ġ�� �̵����� ����
				if (visited[nr][nc]) continue;

				// �湮�� ������ �����ϰ�, ť�� ���� �־� ������ �湮
				visited[nr][nc] = true;
				Q.push(nr * 100 + nc);
			}
		}

		// ���� for���� ���� ������ �̵� Ƚ�� ����
		result++;
	}
}