#include <cstdio>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
int card[10], n, k;
set<int> used;
vector<int> selected;
bool visited[10];
int getSize(int k){
    int ret = 0;
    for (; k; k /= 10, ret++);
    return ret;
}
int _pow(int base, int k){
    int ret = 1;
    for (int i = 0; i < k; i++) {
        ret *= base;
    }
    return ret;
}
void f(int cnt){
    if (cnt == k){
        int val = 0, mul = 1;
        for (int curr : selected){
            val += curr * mul;
            mul *= _pow(10, getSize(curr));
        }
        used.insert(val);
        return;
    }
    for (int i = 0; i < n; i++){
        if (visited[i]) continue;
        visited[i] = true;
        selected.push_back(card[i]);
        f(cnt + 1);
        visited[i] = false;
        selected.pop_back();
    }
}
int main(){
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", card + i);
    f(0);
    printf("%d\n", used.size());
}