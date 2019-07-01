#include <iostream>
using namespace std;
const int MAXTABLE = 1'000'000;
struct _pair{
    bool flag;
    char name[10];
    _pair() : flag(true) {}
};
struct Node{
    Node* next;
    _pair data;
};
Node nodeList[MAXTABLE];
Node hashList[MAXTABLE];
char ansList[MAXTABLE][10];
int N, listCnt, idxCnt;
int idx[MAXTABLE];
void _strcpy(char *dst, const char *src){
    int i = 0;
    for (; src[i]; i++) dst[i] = src[i];
    dst[i] = src[i];
}
int _strcmp(const char *u, const char *v){
    for (int i = 0; ; i++){
        if (u[i] > v[i]) return -1;
        if (u[i] < v[i]) return 1;
        if (!u[i] && !v[i]) return 0; 
    }
}
void _swap(char *u, char *v) {
	char t[10]{};
	_strcpy(t, u);
	_strcpy(u, v);
	_strcpy(v, t);
}
template<typename It, typename Comp>
void _sort(It begin, It end, Comp comp) {
	if (begin == end) return;
	_swap(*begin, *((end - begin) / 2 + begin));
	It piv = begin;
	It left = begin + 1;
	It right = end - 1;
	while (left <= right) {
		while (left <= right && comp(*piv, *left) >= 0) left++;
		while (left <= right && comp(*right, *piv) >= 0) right--;
		if (left <= right) _swap(*left, *right);
	}
	_swap(*piv, *right);
	_sort(begin, right, comp);
	_sort(right + 1, end, comp);
}
int compare(const char *u, const char *v) { return _strcmp(u, v);}
inline unsigned long getHashVal(char *data) {
	unsigned long hash = 5381;
	int c;
	while (c = *data++) hash = (((hash << 5) + hash) + c) % MAXTABLE;
	return hash % MAXTABLE;
}
int isExist(int hVal, char *data){
    /* 
    1 : 해당하는 해쉬값에 원하던 데이터가 존재하고 '출근'처리를 해준 경우
    -1 : 해당하는 해쉬값에 원하던 데이터가 존재하지 않는 경우(collsion만 발생)
    0 : 해당하는 해쉬값에 데이터가 아예 존재하지 않는 경우
    */ 
    Node* curr = hashList[hVal].next;
    if (!curr) return 0;
    while (curr) {
        if (!_strcmp(curr->data.name, data)) {
            curr->data.flag = true;
            return 1;
        }
        curr = curr->next;
    }
    return -1;
}
void _push(char *data){
    int hVal = getHashVal(data);
    int ret = isExist(hVal, data);
    if (ret == 1) return;
    Node* curr = &nodeList[listCnt++];
    _strcpy(curr->data.name, data);
    if (!ret) idx[idxCnt++] = hVal;
    curr->next = hashList[hVal].next;
    hashList[hVal].next = curr;
}
void _erase(char *data){
    int hVal = getHashVal(data);
    Node *curr = hashList[hVal].next;
    while (curr != nullptr && _strcmp(curr->data.name, data)) curr = curr->next;
    curr->data.flag = false;
}
void solve(){
    int p = 0;
    for (int i = 0; i < idxCnt; i++){
        if (!hashList[idx[i]].next) continue;
        Node* curr = hashList[idx[i]].next;
        while (curr) {
            if (curr->data.flag == true) _strcpy(ansList[p++], curr->data.name);
            curr = curr->next;
        }
    }
    _sort(ansList, ansList + p, compare);
    for (int i = 0; i < p; i++) cout << ansList[i] << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++){
        char name[10]{}, cmd[10]{};
        cin >> name >> cmd;
        if (!_strcmp(cmd, "enter")) _push(name);
        else _erase(name);
    }
    solve();
}