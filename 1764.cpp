#include <cstdio>
using namespace std;
const int MAXLEN = 21;
const int MAXSIZE = 500'000;
struct Node{
    char name[MAXLEN];
    Node *next;
};
int listCnt;
Node nodeList[MAXSIZE];
Node hashList[MAXSIZE];
void _strcpy(char *dst, const char *src){
    int i = 0;
    for (; src[i]; i++) dst[i] = src[i];
    dst[i] = src[i];
}
int _strcmp(const char *u, const char *v){
    for (int i = 0; ; i++){
        if (u[i] > v[i]) return 1;
        if (u[i] < v[i]) return -1;
        if (!u[i] && !v[i]) return 0;
    }
}
void _swap(char *u, char *v){
    char t[MAXLEN]{};
    _strcpy(t, u);
    _strcpy(u, v);
    _strcpy(v, t);
}
template <typename It, typename Comp>
void _sort(It begin, It end, Comp comp){
    if (begin == end) return;
    _swap(*begin, *((end - begin) / 2 + begin));
    It piv = begin;
    It left = begin + 1;
    It right = end - 1;
    while (left <= right){
        while (left <= right && comp(*piv, *left) >= 0) left++;
        while (left <= right && comp(*right, *piv) >= 0) right--;
        if (left <= right) _swap(*left, *right); 
    }
    _swap(*piv, *right);
    _sort(begin, right, comp);
    _sort(right + 1, end, comp);
}
int compare(const char *u, const char *v) {return _strcmp(u, v);}
unsigned long getHashVal(char *data){
    unsigned long h = 5381;
    int c;
    while(c = *data++) h = (((h << 10) + h) + c) % MAXSIZE;
    return h % MAXSIZE; 
}
bool getCnt(char *data){
    int h = getHashVal(data);
    Node *curr = hashList[h].next;
    while (curr && _strcmp(curr->name, data)) curr = curr->next;
    if (!curr) return false;
    return true;
}
void push(char *data){
    int h = getHashVal(data);
    Node *node = &nodeList[listCnt++];
    _strcpy(node->name, data);
    node->next = hashList[h].next;
    hashList[h].next = node;
}
char in[MAXLEN];
char nameList[MAXSIZE][MAXLEN];
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int p = 0;
    for (int i = 0; i < N; i++){
        scanf(" %s", in);
        push(in);
    }
    for (int i = 0; i < M; i++){
        scanf(" %s", in);
        if (getCnt(in)) _strcpy(nameList[p++], in);
    }
    _sort(nameList, nameList + p, compare);
    printf("%d\n", p);
    for (int i = 0; i < p; i++) printf("%s\n", nameList[i]);
}