#include <iostream>
#include <algorithm>
using namespace std;
int A[5'000'000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> A[i];
    nth_element(A, A + K - 1, A + N);
    cout << A[K-1] << "\n";
}