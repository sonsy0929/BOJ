#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    int n, v[100]{}; 
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int in;
        scanf("%d", &in);
        v[i] = in;
    }
    queue<int> q;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int k = 1, cnt = 1;
        bool used[100]{};
        q.push(v[i]);
        used[i] = true;
        while(!q.empty()){
            int qSize = q.size();
            for (int s = 0; s < qSize; s++){
                int lo = q.front() - k;
                int hi = q.front() + k;
                q.pop();
                for (int j = 0; j < n; j++){
                    if (used[j]) continue;
                    if (v[j] >= lo && v[j] <= hi) {
                        q.push(v[j]);
                        used[j] = true;
                        cnt++;
                    }
                }
            }
            k++;
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
}