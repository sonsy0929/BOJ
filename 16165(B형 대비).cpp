#include <iostream>
using namespace std;
const int MAX = 100;
struct Node {
    int value;
    char name[MAX + 1];
    Node* next;
};
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
struct Hash {
    Node nodeList[MAX];
    Node hashList[MAX];
    int listCnt;
    Hash() : listCnt(0){}
    unsigned long getHashVal(char *data){
        unsigned long h = 5381;
        int c;
        while (c = *data++) h = (((h << 5) + h) + c) % MAX;
        return h % MAX;
    }
    void push(char *data, int param){
        int hVal = getHashVal(data);
        Node* node = &nodeList[listCnt++];
        _strcpy(node->name, data);
        node->value = param;
        node->next = hashList[hVal].next;
        hashList[hVal].next = node;
    }
    int getValue(char *data){
        int hVal = getHashVal(data);
        Node* curr = hashList[hVal].next;
        while (curr && _strcmp(curr->name, data)) curr = curr->next;
        return curr->value;
    }
};
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
int n, m;
char in[MAX + 1];
char groupList[MAX][MAX + 1];
char memberList[MAX][MAX][MAX + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    Hash G_To_N, M_To_N;
    int p = 0, q, pbList[MAX]{};
    for (int i = 0; i < n; i++){
        int number;
        cin >> in >> number;
        G_To_N.push(in, p);
        _strcpy(groupList[p++], in);
        for (int j = 0; j < number; j++){
            cin >> in;
            M_To_N.push(in, p - 1);
            int &ref = pbList[p - 1];
            _strcpy(memberList[p - 1][ref++], in);
        }
    }
    for (int i = 0; i < m; i++){
        cin >> in >> q;
        if (q) {
            int idx = M_To_N.getValue(in);
            cout << groupList[idx] << "\n";
        }
        else {
            int idx = G_To_N.getValue(in);
            int &ref = pbList[idx];
            _sort(memberList[idx], memberList[idx] + ref, compare);
            for (int i = 0; i < ref; i++) cout << memberList[idx][i] << "\n";
        }
    }
}