#include <iostream>
using namespace std;
const int STRSIZE = 300;
const int MP3SIZE = 250;
char str[MP3SIZE][STRSIZE];
char sorted[MP3SIZE][STRSIZE];
int _compare(char* u, char* v){
    for (int i = 0; ; i++){
        if (!u[i] && !v[i]) return 0;
        if (u[i] != v[i]) return u[i] - v[i];
    }
}
void _strcpy(char* u, char* v){
    int i = 0;
    for (; v[i]; i++){
        u[i] = v[i];
    }
    u[i] = v[i];
}
void merge(int l, int mid, int r){
    int nl = l, nr = mid;
    int pos = l;
    while (nl < mid && nr < r){
        if (_compare(str[nl], str[nr]) <= 0) _strcpy(sorted[pos++], str[nl++]);
        else _strcpy(sorted[pos++], str[nr++]); 
    }
    while (nl < mid) _strcpy(sorted[pos++], str[nl++]);
    while (nr < r) _strcpy(sorted[pos++], str[nr++]);
    for (int i = l; i < r; i++) _strcpy(str[i], sorted[i]);
}
void mergeSort(int l, int r){
    if (l + 1 < r){
        int mid = (l + r) / 2;
        mergeSort(l, mid);
        mergeSort(mid, r);
        merge(l, mid, r);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, num = 1;
    while (1){
        cin >> N;
        if (!N) break;
        cin.ignore();
        for (int i = 0; i < N; i++){
            cin.getline(str[i], STRSIZE);
        }
        mergeSort(0, N);
        cout << num++ << "\n";
        for (int i = 0; i < N; i++){
            cout << str[i] << "\n";
        }
    }
}