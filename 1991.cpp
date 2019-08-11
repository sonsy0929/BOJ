#include <cstdio>
#include <vector>
using namespace std;
vector<char> tree[26];
int f(char c){
    return c - 'A';
}
void preorder(char p){
    if (p == '.') return;
    printf("%c", p);
    preorder(tree[f(p)][0]);
    preorder(tree[f(p)][1]);
}
void inorder(char p){
    if (p == '.') return;
    inorder(tree[f(p)][0]);
    printf("%c", p);
    inorder(tree[f(p)][1]);
}
void postorder(char p){
    if (p == '.') return;
    postorder(tree[f(p)][0]);
    postorder(tree[f(p)][1]);
    printf("%c", p);
}
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        char p, u, v;
        scanf(" %c %c %c", &p, &u, &v);
        tree[f(p)].push_back(u);
        tree[f(p)].push_back(v);
    }
    preorder('A');
    puts("");
    inorder('A');
    puts("");
    postorder('A');
}