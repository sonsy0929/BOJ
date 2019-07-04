#include <cstdio>
#include <vector>
using namespace std;
const int DUMMY = 10;
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> v;
    v.push_back(DUMMY);
    for (int i = 0; i < n; i++){
        char c;
        scanf(" %c", &c);
        int val = c - '0';
        while(k && v.back() < val) {
            v.pop_back();
            k--;
        }
        v.push_back(val);
    }
    for (int i = 1; i < v.size() - k; i++) printf("%d", v[i]);
}