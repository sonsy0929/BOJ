#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, in;
        scanf("%d", &n);
        vector<int> v1;
        for (int i = 0; i < n; i++){
            scanf("%d", &in);
            v1.push_back(in);
        }
        sort(v1.begin(), v1.end());
        scanf("%d", &m);
        vector<int> v2;
        for (int i = 0; i < m; i++){
            scanf("%d", &in);
            v2.push_back(in);
        }
        for (int k : v2){
            bool possible = binary_search(v1.begin(), v1.end(), k);
            printf("%d\n", possible);
        }
    }
}