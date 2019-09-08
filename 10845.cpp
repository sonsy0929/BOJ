#include <iostream>
#include <string>
using namespace std;
const int SIZE = 10'000;
struct Queue{
    int q[SIZE];
    int f, b;
    Queue() : f(0), b(0) {};
    void push(int X){
        q[b] = X;
        b = (b + 1) % SIZE;
    }
    int pop(){
        if (f == b) return -1;
        int front = q[f];
        f = (f + 1) % SIZE;
        return front;
    }
    int front(){
        if (empty()) return -1;
        return q[f];
    }
    int back(){
        if (empty()) return -1;
        return q[b-1];
    }
    int size(){
        return b - f;
    }
    bool empty(){
        return size() == 0;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    Queue q;
    for (int i = 0; i < N; i++){
        string cmd;
        cin >> cmd;
        if (cmd == "push"){
            int val;
            cin >> val;
            q.push(val);
        }
        if (cmd == "pop"){
            cout << q.pop() << "\n";
        }
        if (cmd == "size"){
            cout << q.size() << "\n";
        }
        if (cmd == "empty"){
            cout << q.empty() << "\n";
        }
        if (cmd == "front"){
            cout << q.front() << "\n";
        }
        if (cmd == "back"){
            cout << q.back() << "\n";
        }
    }
}