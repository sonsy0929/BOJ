// Hash

#include <iostream>
using namespace std;
const int MAXSIZE = 10'000;
const int MAXLEN = 11;
struct Node{
    char data[MAXLEN];
    Node *next;
};
Node hashList[MAXSIZE];
Node nodeList[MAXSIZE];
int listCnt;
void _strcpy(char *dst, char *src){
    int i = 0;
    for (; src[i]; i++) dst[i] = src[i];
    dst[i] = src[i];
}
void init(){
    listCnt = 0;
    for (int i = 0; i < MAXSIZE; i++) {
        hashList[i].next = nullptr;
        nodeList[i].next = nullptr;
        for (int j = 0; j < MAXLEN; j++) {
            hashList[i].data[j] = 0;
            nodeList[i].data[j] = 0;
        }
    }
}
bool _strcmp(const char *u, const char *v){
    for (int i = 0; ; i++){
        if (u[i] != v[i]) return false;
        if (!u[i] && !v[i]) return true;
    }
}
int _strlen(const char *in){
    int ret = 0;
    for (; in[ret]; ret++);
    return ret;
}
unsigned long getHashVal(char in[]){
    unsigned long h = 5381;
    int c;
    while (c = *in++) h = (((h << 5) + h) + c) % MAXSIZE;
    return h % MAXSIZE;
}
void add(char in[]){
    unsigned long h = getHashVal(in);
    Node *node = &nodeList[listCnt++];
    _strcpy(node->data, in);
    node->next = hashList[h].next;
    hashList[h].next = node;
}
bool isConsistent(char in[], int bound){
    char data[MAXLEN]{};
    for (int i = 0; i < bound; i++) data[i] = in[i];
    unsigned long h = getHashVal(data);
    Node *curr = hashList[h].next;
    while(curr != nullptr && !_strcmp(curr->data, data)) curr = curr->next;
    return curr != nullptr ? false : true;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        init();
        int n;
        char in[MAXSIZE][MAXLEN]{};
        cin >> n;
        bool consistent = true;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
            add(in[i]);
        }
        for (int i = 0; i < n; i++){
            int len = _strlen(in[i]);
            for (int j = 1; j < len; j++) {
                if (!isConsistent(in[i], j)) {
                    consistent = false;
                    break;
                }
            }
            if (!consistent) break;
        }
        if (consistent) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}

// Trie

#include <cstdio>
using namespace std;
const int SIZE = 10;
struct trie{
    trie* phoneNumber[SIZE];
    bool terminal;
    bool exist;
    trie() : terminal(false), exist(false) {
        for (int i = 0; i < SIZE; i++)
            phoneNumber[i] = nullptr;
    }
    ~trie() {
        for (int i = 0; i < SIZE; i++){
            if (phoneNumber[i]) delete phoneNumber[i];
        }
    }
    bool insert(const char *key){
        if (*key == 0) {
            terminal = true;
            return !exist;
        }
        int next = *key - '0';
        if (!phoneNumber[next]) phoneNumber[next] = new trie();
        exist = true;
        return !terminal && phoneNumber[next]->insert(key + 1);
    }
};
int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        int n;
        scanf("%d", &n);
        trie *root = new trie();
        bool consistent = true;
        for (int i = 0; i < n; i++){
            char in[SIZE + 1];
            scanf(" %s", in);
            if (consistent && !root->insert(in)) consistent = false;
        }
        puts(consistent ? "YES" : "NO");
        delete root;   
    }
}