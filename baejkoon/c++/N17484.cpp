#include <iostream>

using namespace std;

int arr[6][6];
int answer = 9999999;
int n, m;

void dfs(int direction, int r, int c, int sum) {
    if(sum > answer) return;
    if(r+1 == n) {
        answer = min(sum, answer);
    }

    // абго1, го2, ©Лго3
    if(direction == 1) {
        dfs(2, r+1, c, sum+arr[r+1][c]);
        if(c+1<m)
            dfs(3, r+1, c+1, sum+arr[r+1][c+1]);
    }
    else if(direction == 2) {
        if(c-1>=0)
            dfs(1, r+1, c-1, sum+arr[r+1][c-1]);
        if(c+1<m)
            dfs(3, r+1, c+1, sum+arr[r+1][c+1]);
    }
    else if(direction == 3) {
        dfs(2, r+1, c, sum+arr[r+1][c]);
        if(c-1>=0)
            dfs(1, r+1, c-1, sum+arr[r+1][c-1]);
    }
    else {
        dfs(2, r+1, c, sum+arr[r+1][c]);
        if(c-1>=0)
            dfs(1, r+1, c-1, sum+arr[r+1][c-1]);
        if(c+1<m)
            dfs(3, r+1, c+1, sum+arr[r+1][c+1]);
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];

    for(int i=0; i<m; i++)
        dfs(0, 0, i, arr[0][i]);
    
    cout << answer;
    return 0;
}