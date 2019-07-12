#include <cstdio>
#include <queue>
using namespace std;
int main(){
    int N;
    priority_queue<int> pq;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        int in;
        scanf("%d", &in);
        if (!in) {
            if (pq.empty()) puts("0");
            else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else pq.push(in);
    }
}