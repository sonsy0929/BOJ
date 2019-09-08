#include <iostream>
#include <string>
using namespace std;
const int SIZE = 10'000;
struct Stack{
    int stk[SIZE];
    int tp;
    Stack() : tp(0){};
    void push(int X){
        stk[tp++] = X;
    }
    int pop(){
        if (!tp) return -1;
        return stk[--tp];
    }
    int size(){
        return tp;
    }
    bool empty(){
        return tp == 0;
    }
    int top(){
        if (empty()) return -1;
        return stk[tp-1];
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    Stack stk;
    for (int i = 0; i < N; i++){
        string cmd;
        cin >> cmd;
        if (cmd == "push"){
            int val;
            cin >> val;
            stk.push(val);
        }
        if (cmd == "top"){
            cout << stk.top() << "\n";
        }
        if (cmd == "size"){
            cout << stk.size() << "\n";
        }
        if (cmd == "empty"){
            cout << stk.empty() << "\n";
        }
        if (cmd == "pop"){
            cout << stk.pop() << "\n";
        }
    }
}