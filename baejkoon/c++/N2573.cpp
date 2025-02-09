#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[300][300];

void melt(const int& n, const int& m) {
    int arr2[300][300];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            arr2[i][j] = arr[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int cnt = 0;
            if(arr[i][j] != 0) {
                if(arr[i-1][j] == 0) cnt++;
                if(arr[i+1][j] == 0) cnt++;
                if(arr[i][j-1] == 0) cnt++;
                if(arr[i][j+1] == 0) cnt++;
            }
            arr2[i][j] = max(0, arr[i][j]-cnt);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            arr[i][j] = arr2[i][j];
        }
    }
}

// 1 - 하나임, 2 이상 - 분리됨, 0 모두 녹음
int isSeparated(int n, int m) {
    int check[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            check[i][j] = 0;
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] != 0 && check[i][j] == 0) {
                cnt++;
                queue<pair<int, int>> q;
                q.push({i, j});
                check[i][j] = 1;

                while(!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;

                    q.pop();

                    int a[] = {0, 0, 1, -1};
                    int b[] = {1, -1, 0, 0};
                    for(int k=0; k<4; k++) {
                        int dy = a[k] + y;
                        int dx = b[k] + x;

                        if(arr[dy][dx] != 0 && check[dy][dx] == 0) {
                            q.push({dy, dx});
                            check[dy][dx] = 1;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    int answer = 0;
    while(true) {
        int v = isSeparated(n, m);
        if(v == 0) {
            answer = 0;
            break;
        }
        if(v >= 2) break;
        melt(n, m);
        answer++;
    }

    cout << answer;
    return 0;
}