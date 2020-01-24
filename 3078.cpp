/*
정해는 "스위핑, 큐, 슬라이딩 윈도우"이다.
대부분의 소스들이 슬라이딩 윈도우로 되어 있는데,
나는 다른 풀이가 떠올라서 이런 방식으로 풀었다.
먼저 이름의 길이를 기준으로 성적을 넣어준다.
이 때 성적이 자동으로 오름차순으로 정렬이 되는데,
이를 이용하여 upper_bound를 사용해서 좋은 친구의 후보군이 몇 명인지 세었다.
이후, 각 친구에 해당하는 좋은 친구의 수를 더해주어 쌍의 개수를 count해주었다.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> RANK[300'000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        RANK[in.size()].push_back(i);
    }
    long long ans = 0;
    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j < RANK[i].size(); j++) {
            int curr = RANK[i][j];
            auto uit = upper_bound(RANK[i].begin(), RANK[i].end(), curr + K);
            if (uit != RANK[i].end()) {
                int idx = uit - RANK[i].begin();
                ans += idx - j - 1;
            } else {
                ans += RANK[i].size() - j - 1;
            }
        }
    }
    cout << ans << "\n";
}