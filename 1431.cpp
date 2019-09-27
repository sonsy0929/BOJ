#include <iostream>
using namespace std;
const int STRSIZE = 60;
const int SIZE = 1010;
int _strlen(char *data){
    int ret = 0;
    while (*data++) ret++;
    return ret;
}
int _strcmp(char *u, char *v){
    for (int i = 0; ;i++){
        if (u[i] != v[i]) return v[i] - u[i];
    }
}
void _strcpy(char *u, char *v){
    while (*u++ = *v++);
}
struct Serial{
    char serial[SIZE];
    int sum, len;
    int getSum(char* u){
        int uSum = 0;
        while(*u){
            int number = *u - '0';
            if (number >= 0 && number <= 9) uSum += number;
            u++;
        }
        return uSum;
    }
    bool operator<(Serial &v){
        if (this->len != v.len) return this->len < v.len;
        else if (this->sum != v.sum) return this->sum < v.sum;
        return _strcmp(this->serial, v.serial) > 0;
    }
    void push(char* data){
        _strcpy(serial, data);
        sum = getSum(data);
        len = _strlen(data);
    }
};
Serial S[SIZE];
char in[STRSIZE];
void mergeSort(int s, int mid, int e){
    Serial sorted[SIZE];
    int l = s, r = mid, pos = l;
    while (l < mid && r < e){
        if (S[l] < S[r]) sorted[pos++] = S[l++];
        else sorted[pos++] = S[r++];
    }
    while (l < mid) sorted[pos++] = S[l++];
    while (r < e) sorted[pos++] = S[r++];
    for (int i = s; i < e; i++) S[i] = sorted[i];
}
void merge(int s, int e){
    if (s + 1 < e){
        int mid = (s + e) / 2;
        merge(s, mid);
        merge(mid, e);
        mergeSort(s, mid, e);    
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> in;
        S[i].push(in);
    }
    merge(0, N);
    for (int i = 0; i < N; i++){
        cout << S[i].serial << "\n";
    }
}