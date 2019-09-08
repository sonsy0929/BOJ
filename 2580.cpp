#include <cstdio>
using namespace std;
int sudoku[9][9];
bool R[10][9], C[10][9], SN[10][9];
int getSquareNumber(int r, int c){
    return 3 * (r / 3) + c / 3;
}
bool f(int pos){
    if (pos == 81) return true;
    if (sudoku[pos/9][pos%9]) return f(pos+1);
    int sn = getSquareNumber(pos/9, pos%9);
    for (int i = 1; i <= 9; i++){
        if (R[i][pos/9] || C[i][pos%9] || SN[i][sn]) continue;
        sudoku[pos/9][pos%9] = i;
        R[i][pos/9] = C[i][pos%9] = SN[i][sn] = true;
        if (f(pos+1)) return true;
        sudoku[pos/9][pos%9] = 0;
        R[i][pos/9] = C[i][pos%9] = SN[i][sn] = false;
    }
    return false;
}
int main(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            int in;
            scanf("%d", &in);
            sudoku[i][j] = in;
            int sn = getSquareNumber(i,j);
            if (in) R[in][i] = C[in][j] = SN[in][sn] = true; 
        }
    }
    f(0);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            printf("%d ", sudoku[i][j]);
        }
        puts("");
    }
}