/*
시간복잡도 : O(N^3 * logK)

a가 b를 지목했다면, a에서 b로 가는 간선을 만들어준다.
a에서 시작해 k번 지목해서 b가 걸렸다는 것은, a에서 간선을 k개 타고 b에 도착한 것과 같다.
이는 인접행렬의 거듭제곱을 통해 이러한 경로의 존재여부를 빠르게 확인할 수 있다.
*/
#include <bits/stdc++.h>
using namespace std;
int N, K, M;
struct Matrix {
    int N;
    vector<vector<int>> mat;
    Matrix() {}
    Matrix(int n) : N(n) {
        mat = vector<vector<int>>(N, vector<int>(N, 0));
    }
    Matrix operator*(const Matrix& v) {
        Matrix ret(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    if (this->mat[i][k] && v.mat[k][j]) ret.mat[i][j] = 1;
                }
            }
        }
        return ret;
    }
    Matrix operator^(int k) {
        if (k == 1) return *this;
        Matrix ret = *this ^ (k / 2);
        ret = ret * ret;
        if (k & 1) ret = ret * (*this);
        return ret;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> N >> K >> M;
    Matrix Mat(N);
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        Mat.mat[i][u] = Mat.mat[i][v] = 1;
    }
    Mat = Mat ^ K;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (Mat.mat[u][v]) {
            cout << "death\n";
        } else {
            cout << "life\n";
        }
    }
}