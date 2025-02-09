#include <iostream>

using namespace std;

int n;
int m[17][17];
int answer;

void Dfs(int r, int c, int stat) {
    if(r == n && c == n) {
        answer++;
        return;
    }

    if(stat == 1 || stat == 3) {
        if(c+1<=n && m[r][c+1] == 0) {
            Dfs(r, c+1, 1);
        }
    }
    if(stat == 2 || stat == 3) {
        if(r+1<=n && m[r+1][c] == 0) {
            Dfs(r+1, c, 2);
        }
    }

    if(c+1<=n && r+1<=n && m[r][c+1] == 0 && m[r+1][c] == 0 && m[r+1][c+1] == 0) {
        Dfs(r+1, c+1, 3);
    }
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> m[i][j];
    // 1: 가로, 2: 세로, 3: 대각선
    Dfs(1, 2, 1);

    cout << answer;

    return 0;
}