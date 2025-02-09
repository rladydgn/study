#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    int arr[n][m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            arr[i][j] = 0;

    for(int i=0; i<k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int r=a; r<c; r++) {
            for(int c=b; c<d; c++) {
                arr[r][c] = 1;
            }
        }
    }

    vector<int> answer;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] == 0) {
                queue<pair<int, int>> q;
                q.push({i, j});
                arr[i][j] = 1;
                int cnt = 0;

                while(!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;

                    q.pop();
                    cnt++;

                    int r[] = {0, 0, 1, -1};
                    int c[] = {1, -1, 0, 0};

                    for(int k=0; k<4; k++) {
                        int dr = y + r[k];
                        int dc = x + c[k];

                        if(dr<n && dr>=0 && dc<m && dc>=0 && arr[dr][dc] == 0) {
                            arr[dr][dc] = 1;
                            q.push({dr, dc});
                        }
                    }
                }
                answer.push_back(cnt);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for(int i=0; i<answer.size(); i++)
        cout << answer[i] << " ";
    
    return 0;
}