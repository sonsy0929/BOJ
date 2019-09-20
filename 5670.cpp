#include <cstdio>
using namespace std;
#define nullptr 0
const int LISTSIZE = 1e5;
const int SIZE = 26;
const int STRSIZE = 81;
struct Trie{
    Trie* go[SIZE];
    bool terminal;
    int cnt;
    Trie() : terminal(false), cnt(0){
        for (int i = 0; i < SIZE; i++){
            go[i] = nullptr;
        }
    }
    ~Trie(){
        for (int i = 0; i < SIZE; i++){
            if (go[i]) delete go[i];
        }
    }
    void insert(char* data){
        if (*data == '\0'){
            terminal = true;
            return;
        }
        int next = *data - 'a';
        if (!go[next]){
            go[next] = new Trie();
            cnt++;
        }
        go[next]->insert(data+1);
    }
    int getInputCnt(char* data){
    }
};
void strcpy(char *dst, const char *src){
    int i = 0;
    for (; src[i]; i++){
        dst[i] = src[i];
    }
    dst[i] = src[i];
}
char list[LISTSIZE][STRSIZE];
char in[STRSIZE];
int main(){
    int N;
    while(scanf("%d", &N) != -1){
        Trie trie;
        for (int i = 0; i < N; i++){
            scanf(" %s", in);
            trie.insert(in);
            strcpy(list[i], in);
        }
        int ans = 0;
        for (int i = 0; i < N; i++){
            ans += trie.getInputCnt(list[i]);
        }
        printf("%d\n", ans);
    }
}