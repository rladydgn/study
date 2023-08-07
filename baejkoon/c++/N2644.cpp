#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
int visited[101];

int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int r, c;
        cin >> r >> c;
        arr[r][c] = 1;
        arr[c][r] = 1;
    }

    queue<pair<int, int>> q;
    q.push({a, 0});
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        if(p.first == b) {
            cout << p.second;
            return 0;
        }

        for(int i=1; i<=n; i++) {
            if(arr[p.first][i] && !visited[i]) {
                q.push({i, p.second+1});
                visited[i] = 1;
            }
        }
    }
    cout << -1;
    return 0;
}