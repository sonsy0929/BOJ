/*
B���� ���� �ٸ� �ܾ ����ϸ� �ȴ�.
�̶� 15! >= 100'000�̹Ƿ� ���ڿ� B�� ���̴� 15���̸� �ǰ�,
next_permutation�� �̿��ؼ� ���� �ٸ� �ܾ ���� �̸� ����ϸ� �ȴ�!
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s = "abcdefghijklmno";
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m - 1; i++){
        cout << s << " ";
        next_permutation(s.begin(), s.end());
    }
    cout << s;
}