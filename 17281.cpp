#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    vector<int> v[50];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 9; j++){
            int in;
            scanf("%d", &in);
            v[i].push_back(in);
        }
    }
    int order[9]{};
    for (int i = 1; i < 9; i++) order[i] = i;
    int ans = 0, pos = 0;
    do {
        int idx = 0, sum = 0;
        for (int i = 0; i < n; i++){
            vector<int> &ref = v[i];
            swap(order[0], order[3]);
            int val = 0, out = 0;
            int place[4]{};
            while (out != 3) {
                int curr = ref[order[idx]];
                if (!curr) {
                    out++;
                    idx = (idx + 1) % 9;
                    continue;
                }
                for (int i = 3; i >= 1; i--){
                    if (!place[i]) continue;
                    if (i + curr > 3) val++;
                    else place[i + curr] = 1;
                    place[i] = 0;
                }
                if (curr == 4) val++;
                else place[curr] = 1;
                idx = (idx + 1) % 9;
            }
            sum += val;
            swap(order[3], order[0]); 
        }
        ans = max(ans, sum);
    } while(next_permutation(order + 1, order + 9));
    printf("%d\n", ans);
}