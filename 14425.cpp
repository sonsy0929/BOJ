#include <cstdio>
using namespace std;
const int MAXLEN = 501;
const int MAXSIZE = 10'000;
struct Node{
    char data[MAXLEN];
    Node* next;  
};
int listCnt;
Node hashList[MAXSIZE];
Node nodeList[MAXSIZE];
bool _strcmp(const char *u, const char *v){
    for (int i = 0; ; i++){
        if (u[i] != v[i]) return false;
        if (!u[i] && !v[i]) return true;
    }
}
bool _strcpy(char *dst, const char *src){
    int i = 0;
    for (; src[i]; i++) dst[i] = src[i];
    dst[i] = src[i];
}
unsigned long getHashVal(const char *in){
    unsigned long h = 5381;
    int c;
    while (c = *in++) h = (((h << 5) + h) + c) % MAXSIZE;
    return h % MAXSIZE;
}
void add(const char *in){
    unsigned long h = getHashVal(in);
    Node *curr = &nodeList[listCnt++];
    _strcpy(curr->data, in);
    curr->next = hashList[h].next;
    hashList[h].next = curr;
}
bool isInclude(const char *in){
    unsigned long h = getHashVal(in);
    Node *curr = hashList[h].next;
    while (curr && !_strcmp(curr->data, in)) curr = curr->next;
    return curr != nullptr ? true : false;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    char in[MAXLEN]{};
    for (int i = 0; i < n; i++){
        scanf(" %s", in);
        add(in);
    }
    int ans = 0;
    for (int i = 0; i < m; i++){
        scanf(" %s", in);
        if (isInclude(in)) ans++;
    }
    printf("%d\n", ans);
}