#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int arr[50][50];
int N, L, R;

void Dfs(int cnt) {
    bool tf = true;
    int check[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            check[i][j] = 0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int a[] = {0, 0, 1, -1};
            int b[] = {1, -1, 0, 0};

            for(int k=0; k<4; k++) {
                int dr = i + a[k];
                int dc = j + b[k];
                // cout << check[i][j] << " " << check[dr][dc] << " " << dr << " " << dc << endl;
                if(dr>=0 && dr<N && dc>=0 && dc<N && abs(arr[i][j]-arr[dr][dc]) >= L && abs(arr[i][j]-arr[dr][dc]) <= R && check[i][j] == 0 && check[dr][dc] == 0) {
                    tf = false;
                    queue<pair<int, int>> q, q2;
                    q.push({i, j});
                    q.push({dr, dc});
                    q2.push({i, j});
                    q2.push({dr, dc});
                    check[i][j] = 1;
                    check[dr][dc] = 1;
                    int sum = 0;
                    while(!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        sum += arr[p.first][p.second];

                        for(int l=0; l<4; l++) {
                            int dr = p.first + a[l];
                            int dc = p.second + b[l];

                            if(dr>=0 && dr<N && dc>=0 && dc<N && abs(arr[p.first][p.second]-arr[dr][dc]) >= L && abs(arr[p.first][p.second]-arr[dr][dc]) <= R && check[dr][dc] == 0) {
                                q.push({dr, dc});
                                q2.push({dr, dc});
                                check[dr][dc] = 1;
                            }
                        }
                    }
                    int value = sum/q2.size();
                    int q2_s = q2.size();
                    while(!q2.empty()) {
                        pair<int, int> p = q2.front();
                        // cout << p.first << " " << p.second << endl;
                        q2.pop();
                        arr[p.first][p.second] = value;
                    }
                    // cout << endl;
                }
            }
        }
    }
    if(tf) {
        cout << cnt;
    }
    else {
        Dfs(cnt+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L >> R;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> arr[i][j];

    Dfs(0);
    return 0;
}