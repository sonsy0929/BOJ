#include <iostream>
using namespace std;
const int SIZE = 10'000'001;
template<typename T>
void _swap(T &u, T &v){
    T tmp = u;
    u = v;
    v = tmp;
}
template<typename T>
struct Heap{
    const int TOP = 1;
    T heap[SIZE];
    int size;
    Heap() : size(0) {} 
    bool empty(){
        return !size;
    }
    T top(){
        return heap[TOP];
    }
    void push(T n){
        heap[++size] = n;
        int i = size;
        while (i/2){
            if (heap[i/2] < heap[i]) _swap(heap[i/2], heap[i]);
            i/=2;
        }
    }
    void pop(){
        if (!size) return;
        heap[TOP] = heap[size--];
        int i = TOP;
        while (1){
            int L, R, CHILD;
            L = (i * 2 <= size ? i * 2 : -1);
            R = (i * 2 + 1 <= size ? i * 2 + 1 : -1);
            
            if (L == -1 && R == -1) break;
            else if (R == -1) CHILD = L;
            else CHILD = (heap[L] < heap[R] ? R : L);
            
            if (heap[CHILD] > heap[i]) _swap(heap[i], heap[CHILD]);
            i = CHILD;
        }
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << fixed;
    cout.precision(3);
    int n;
    cin >> n;
    Heap<double> pq;
    for (int i = 0; i < n; i++){
        double in;
        cin >> in;
        pq.push(-in);
    }
    for (int i = 0; i < 7; i++){
        cout << -pq.top() << "\n";
        pq.pop();
    }
}