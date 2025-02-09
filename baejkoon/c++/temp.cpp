#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// n, m, k;
int visited[50][50][51];

int solution(vector<string> grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    int answer = -1;
    // ¾ß¿µÈ½¼ö, ³²ÀºÀÌµ¿È½¼ö, row, col
    priority_queue<pair<int, vector<int>>> pq;
    pq.push({0, {k, 0, 0}});
    visited[0][0][k] = 1;
    while(!pq.empty()) {
        int camp = pq.top().first;
        vector<int> v = pq.top().second;
        pq.pop();

        if(v[1] == n-1 && v[2] == m-1) {
            answer = -camp;
            break;
        }

        if(v[0] != k && !visited[v[1]][v[2]][k] && grid[v[1]][v[2]] == '.') {
            visited[v[1]][v[2]][k] = 1;
            pq.push({camp-1, {k, v[1], v[2]}});
        }

        if(v[0] == 0) continue;

        int y[] = {0, 0, 1, -1};
        int x[] = {1, -1, 0, 0};
        for(int i=0; i<4; i++) {
            int dy = v[1] + y[i];
            int dx = v[2] + x[i];

            if(dy>=0 && dy<n && dx>=0 && dx<m && grid[dy][dx] != '#' && !visited[dy][dx][v[0]-1]) {
                visited[dy][dx][v[0]-1] = 1;
                pq.push({camp, {v[0]-1, dy, dx}});
            }
        }

        // cout << v[1] << " " << v[2] << " " << v[0] << " " << visited[v[1]][v[2]][k] << " " << grid[v[1]][v[2]] << endl;
    }
    return answer;
}