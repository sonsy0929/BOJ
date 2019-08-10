#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1e9 + 1;
int main(){
    int N;
    scanf("%d", &N);
    vector<int> v(1, -MAX);
    for (int i = 0; i < N; i++){
        int in;
        scanf("%d", &in);
        if (v.back() < in) v.push_back(in);
        else *lower_bound(v.begin(), v.end(), in) = in; 
    }
    printf("%d\n", v.size() - 1);
}