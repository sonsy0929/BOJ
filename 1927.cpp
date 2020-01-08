#include <cstdio>
using namespace std;
const int SIZE = 100'009;
template <typename T>
void swap(T &u, T &v){
    T tmp = u;
    u = v;
    v = tmp;
}
template <typename T>
struct Heap{
    static const int TOP = 1;
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
            if (heap[i/2] < heap[i]) swap(heap[i/2], heap[i]);
            i/=2;
        }
    }
    void pop(){
        heap[TOP] = heap[size--];
        int i = TOP;
        while(1){
            int child;
            int l = i*2 <= size ? i*2 : -1;
            int r = i*2+1 <= size ? i*2+1 : -1;
            
            if (l == -1 && r == -1) break;
            else if (r == -1) child = l;
            else child = heap[l] < heap[r] ? r : l;
            
            if (heap[i] < heap[child]) swap(heap[i], heap[child]);
            i = child;
        }
    }
};
int main(){
    int n;
    scanf("%d", &n);
    Heap<int> heap;
    while(n--){
        int k;
        scanf("%d", &k);
        if (k) heap.push(-k);
        else{
            if (heap.empty()) puts("0");
            else{
                printf("%d\n", -heap.top());
                heap.pop();
            }
        }
    }
}