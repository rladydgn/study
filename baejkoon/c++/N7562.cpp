#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n;
        cin >> n;
        int visited[n][n];
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                visited[j][k] = 0;
        pair<int, int> now, target;
        int a, b;
        cin >> a >> b;
        now = {a, b};
        cin >> a >> b;
        target = {a, b};

        queue<pair<int, pair<int, int>>> q;
        q.push({0, now});
        while(!q.empty()) {
            int cnt = q.front().first;
            pair<int, int> cor = q.front().second;
            q.pop();

            if(cor.first == target.first && cor.second == target.second) {
                cout << cnt << "\n";
                break;
            }

            int r[] = {-2, -1, 1, 2, 2, 1, -1, -2};
            int c[] = {1, 2, 2, 1, -1, -2, -2, -1};

            for(int i=0; i<8; i++) {
                int dr = cor.first + r[i];
                int dc = cor.second + c[i];
                if(dr>=0 && dr<n && dc>=0 && dc<n && visited[dr][dc] == 0) {
                    visited[dr][dc] = 1;
                    q.push({cnt+1, {dr, dc}});
                }
            }
        }
    }
    return 0;
}