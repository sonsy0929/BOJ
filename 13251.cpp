#include <cstdio>
#include <vector>
using namespace std;
int main(){
    int M, K, cnt = 0;
    scanf("%d", &M);
    vector<int> in;
    for (int i = 0; i < M; i++){
        int val;
        scanf("%d", &val);
        in.push_back(val);
        cnt += val;
    }
    scanf("%d", &K);
    vector<double> res;
    for (int i = 0; i < M; i++){
        if (in[i] < K) continue;
        int val = in[i];
        double pr = 1.0;
        for (int j = 0; j < K; j++){
            pr *= double(val - j) / double(cnt - j); 
        }
        res.push_back(pr);
    }
    double ans = 0;
    for (double pr : res) ans += pr;
    printf("%.10lf", ans);
}