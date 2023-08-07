#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[101][101];
int visited[101][101];
int n, m;

void Bfs(int a, int b) {
    // 외부 공기의 값을 2로 설정
    queue<pair<int, int>> q;
    q.push({a, b});
    arr[a][b] = 2;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        int x[] = {0, 0, 1, -1};
        int y[] = {1, -1, 0, 0};
        for(int i=0; i<4; i++) {
            int dx = p.second + x[i];
            int dy = p.first + y[i];
            if(dx>=0 && dx<m && dy>=0 && dy<n && arr[dy][dx] == 0) {
                q.push({dy, dx});
                arr[dy][dx] = 2;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    Bfs(0, 0);

    // 삭제될 치즈
    int times = 0;
    int cnt = 0;
    while(true) {
        bool check = false;
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(arr[i][j] == 1) {
                    int x[] = {0, 0, 1, -1};
                    int y[] = {1, -1, 0, 0};
                    for(int k=0; k<4; k++) {
                        int dx = j + x[k];
                        int dy = i + y[k];
                        if(dx>=0 && dx<m && dy>=0 && dy<n && arr[dy][dx] == 2) {
                            v.push_back({i, j});
                            arr[i][j] = 0;
                            check = true;
                            break;
                        }
                    }
                }
            }
        }
        if(!check) break;
        times = v.size();
        cnt++;
        for(int i=0; i<v.size(); i++) {
            Bfs(v[i].first, v[i].second);
        }
    }

    cout << cnt << "\n" << times;
    return 0;
}