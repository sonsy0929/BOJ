#include <cstdio>
using namespace std;
#define nullptr 0
const int STRSIZE = 81;
const int SIZE = 1e5;
const int alphaSize = 26;
struct Trie{
    Trie* go[alphaSize];
    bool terminal;
    int childCnt;
    int words;
    Trie() : terminal(false), childCnt(0), words(0) {
        for (int i = 0; i < alphaSize; i++){
            go[i] = nullptr;
        }
    }
    ~Trie() {
        for (int i = 0; i < alphaSize; i++){
            if (go[i]) delete go[i];
        }
    }
    void insert(char* data){
        if (*data == nullptr){
            terminal = true;
            childCnt++;
            return;
        }
        int next = *data - 'a';
        if (!go[next]){
            go[next] = new Trie();
            childCnt++;
        }
        words++;
        go[next]->insert(data+1);
    }
    int buttonClickCnt(bool isRoot = false){
        int ret = (isRoot || childCnt > 1) ? words : 0;
        for (int i = 0; i < alphaSize; i++){
            if (go[i]) ret += go[i]->buttonClickCnt(); 
        }
        return ret;
    }
};
char in[STRSIZE];
int main(){
    int N;
    while (scanf("%d", &N) != -1){
        Trie root;
        for (int i = 0; i < N; i++){
            scanf(" %s", in);
            root.insert(in);
        }
        int ret = root.buttonClickCnt(true);
        double ans = (double)ret / (double)N;
        printf("%.2f\n", ans);
    }
}