/*
B개의 서로 다른 단어를 출력하면 된다.
이때 15! >= 100'000이므로 문자열 B의 길이는 15자이면 되고,
next_permutation을 이용해서 서로 다른 단어를 조합 이를 출력하면 된다!
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