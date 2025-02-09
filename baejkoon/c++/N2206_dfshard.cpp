#include <iostream>
#include <queue>
#include <string>

using namespace std;

int mp[1001][1001];
int visited[1001][1001][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        string tmp;
        cin >> tmp;
        for(int j=1; j<=tmp.size(); j++) {
            mp[i][j] = tmp[j-1] - '0';
        }
    }

    queue<vector<int>> q;
    // 횟수, 벽부순여부, row, column 좌표
    q.push(vector<int> {0, 1, 1});
    visited[1][1][0] = 1;

    while(!q.empty()) {
        vector<int> v = q.front();
        q.pop();

        if(v[1] == n && v[2] == m) {
            cout << visited[n][m][v[0]];
            return 0;
        }

        // cout << v[0] << " " << v[1] << " " << v[2] << " " << visited[v[1]][v[2]][v[0]] << endl;

        int a[4] = {0, 0, 1, -1};
        int b[4] = {1, -1, 0, 0};

        for(int i=0; i<4; i++) {
            int r = v[1] + a[i];
            int c = v[2] + b[i];

            if(r>=1 && r<=n && c>=1 && c<=m) {
                if(mp[r][c] == 1 && v[0] == 0 && visited[r][c][1] == 0) {
                    // cout << "t " << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
                    visited[r][c][1] = visited[v[1]][v[2]][0] + 1;
                    q.push({1, r, c});
                }
                else if(mp[r][c] == 0 && visited[r][c][v[0]] == 0) {
                    // cout << "tt " << visited[v[1]][v[2]][v[0]] << endl;
                    visited[r][c][v[0]] = visited[v[1]][v[2]][v[0]] + 1;
                    // cout << "tt " << visited[r][c][v[0]] << endl;
                    q.push({v[0], r, c});
                }
            }
        }
    }
    cout << -1;
    return 0;
}