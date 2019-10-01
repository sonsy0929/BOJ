#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    vector<int> cows(n,0);
    for (int i = 0; i < n; i++) scanf("%d", &cows[i]);
    sort(cows.begin(),cows.end(), greater<int>());
    int s = 0, e = 0;
    while (e - s <= cows[e]) e++;
    printf("%d\n", e - s);
}