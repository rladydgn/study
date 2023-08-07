#include <iostream>
#include <queue>

using namespace std;

int arr[20][20];
int visited[20][20];
int answer;
int shark_size = 2, eat_cnt = 0;
int shark_pos[2];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 9) {
                shark_pos[0] = i;
                shark_pos[1] = j;
            }
        }
    }
    while(true) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                visited[i][j] = 0;
            }
        }
        // cout << answer << endl;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {shark_pos[0], shark_pos[1]}});
        visited[shark_pos[0]][shark_pos[1]] = 1;
        arr[shark_pos[0]][shark_pos[1]] = 0;
        bool check = false;

        while(!q.empty()) {
            pair<int, pair<int, int>> p = q.front();
            // cout << p.first << endl;
            q.pop();

            if(arr[p.second.first][p.second.second] != 0 && arr[p.second.first][p.second.second] < shark_size) {
                arr[p.second.first][p.second.second] = 0;

                shark_pos[0] = p.second.first;
                shark_pos[1] = p.second.second;
                answer += p.first;

                eat_cnt += 1;
                if(shark_size == eat_cnt) {
                    shark_size += 1;
                    eat_cnt = 0;
                }
                check = true;
                break;
            }

            int y[] = {-1, 0, 0, 1};
            int x[] = {0, -1, 1, 0};
            for(int i=0; i<4; i++) {
                int dy = y[i] + p.second.first;
                int dx = x[i] + p.second.second;

                if(dy>=0 && dy<n && dx>=0 && dx<n && arr[dy][dx] <= shark_size && !visited[dy][dx]) {
                    q.push({p.first+1, {dy, dx}});
                    visited[dy][dx] = 1;
                }
            }
        }
        if(!check) break;
    }
    cout << answer;

    return 0;
}