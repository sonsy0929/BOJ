#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
const int roff[] = {-1,1,0,0};
const int coff[] = {0,0,-1,1};
string dest = "123456780";
bool isIN(int r, int c){
    if (r < 0 || c < 0 || r >= 3 || c >= 3) return false;
    return true;
}
int bfs(string start){
    queue<string> q;
    set<string> visited;
    q.push(start);
    visited.insert(start);
    int ret = 0;
    for (; !q.empty(); ret++){
        int qSize = q.size();
        for (int s = 0; s < qSize; s++){
            auto curr = q.front();
            q.pop();
            if (curr == dest) return ret;
            int i = 0, r, c;
            for (; curr[i] != '0'; i++);
            r = i / 3, c = i % 3;
            for (int d = 0; d < 4; d++){
                int nr = r + roff[d], nc = c + coff[d];
                if (!isIN(nr, nc)) continue;
                int j = nr * 3 + nc;
                auto next = curr;
                swap(next[i], next[j]);
                if (!visited.count(next)){
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
    }
    return -1;
}
int main(){
    string s;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            char c;
            cin >> c;
            s.push_back(c);
        }
    }
    cout << bfs(s) << "\n";
}