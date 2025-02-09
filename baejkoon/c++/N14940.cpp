#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[1000][1000];
int visited[1000][1000];
pair<int, int> target;

void print() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void bfs() {
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {target.first, target.second}});
    visited[target.first][target.second] = 1;

    while(!q.empty()) {
        int distance = q.front().first;
        pair<int, int> cor = q.front().second;

        arr[cor.first][cor.second] = distance;
        q.pop();

        int y[] = {0, 0, 1, -1};
        int x[] = {1, -1, 0, 0};
        for(int i=0; i<4; i++) {
            int dy = cor.first + y[i];
            int dx = cor.second + x[i];

            if(dy>=0 && dy<n && dx>=0 && dx<m && visited[dy][dx] == 0 && arr[dy][dx] == 1) {
                q.push({distance+1, {dy, dx}});
                visited[dy][dx] = 1;
            }
        }
    }
}

void check() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(visited[i][j] == 0 && arr[i][j] == 1) arr[i][j] = -1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) target = {i, j};
        }
    }

    bfs();
    check();
    print();
}