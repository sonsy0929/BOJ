#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> preorder;
void postorder(int l, int r){
    if (l > r) return;
    int root = preorder[l];
    int s = l, e = r;
    while (preorder[e] > root) e--;
    postorder(s + 1, e);
    postorder(e + 1, r);
    printf("%d\n", root);
}
int main(){
    int in;
    while(scanf("%d", &in) != -1) preorder.push_back(in);
    postorder(0, preorder.size() - 1);
}