#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[500][500], visited[500][500];
int answer;

void Dfs(int i, int j, int cnt, int s) {
    if(cnt == 4) {
        if(answer < s)
            answer = s;
        return;
    }

    int r[] = {0, 0, 1, -1};
    int c[] = {1, -1, 0, 0};

    for(int k=0; k<4; k++) {
        int dr = i + r[k];
        int dc = j + c[k];

        if(dr>=0 && dr<n && dc>=0 && dc<m && visited[dr][dc] == 0) {
            visited[dr][dc] = 1;
            Dfs(dr, dc, cnt+1, s+arr[dr][dc]);
            // ㅏ ㅓ ㅗ ㅜ 탐색을 위해 다시 돌아감
            Dfs(i, j, cnt+1, s+arr[dr][dc]);
            visited[dr][dc] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visited[i][j] = 1;
            Dfs(i, j, 1, arr[i][j]);
            visited[i][j] = 0;
        }
    }
    cout << answer;
    return 0;
}