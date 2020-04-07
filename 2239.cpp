#include <bits/stdc++.h>
using namespace std;
int R[10][10], C[10][10], S[10][10], sudoku[10][10];
int get(int r, int c) {
    return (r / 3) * 3 + c / 3;
}
void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d", sudoku[i][j]);
        }
        puts("");
    }
}
bool f(int curr) {
    if (curr == 81) {
        print();
        return true;
    }
    int r = curr / 9, c = curr % 9;
    int sn = get(r, c);
    if (sudoku[r][c]) return f(curr + 1);
    for (int i = 1; i <= 9; i++) {
        if (R[r][i] || C[c][i] || S[sn][i]) continue;
        R[r][i] = C[c][i] = S[sn][i] = 1;
        sudoku[r][c] = i;
        if (f(curr + 1)) return true;
        R[r][i] = C[c][i] = S[sn][i] = 0;
        sudoku[r][c] = 0;
    }
    return false;
}
int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int in;
            scanf("%1d", &in);
            sudoku[i][j] = in;
            if (in) R[i][in] = C[j][in] = S[get(i, j)][in] = 1;
        }
    }
    f(0);
}