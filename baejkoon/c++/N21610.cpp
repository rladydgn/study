#include <iostream>
#include <vector>

using namespace std;

int arr[50][50];
vector<pair<int, int>> cloud;
int visited[50][50];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    // 첫 구름
    cloud.push_back({n-1, 0});
    cloud.push_back({n-1, 1});
    cloud.push_back({n-2, 0});
    cloud.push_back({n-2, 1});

    for(int i=0; i<m; i++) {
        int d, s;
        cin >> d >> s;
        // 구름 이동, 바구니 비 증가
        for(int j=0; j<cloud.size(); j++) {
            // 구름 이동
            if(d == 1 || d == 2 || d == 8) {
                cloud[j].second = (n - (s-cloud[j].second) % n) % n;
            }
            if(d == 2 || d == 3 || d == 4) {
                cloud[j].first = (n - (s-cloud[j].first) % n) % n;
            }
            if(d == 4 || d == 5 || d == 6) {
                cloud[j].second = (s+cloud[j].second) % n;
            }
            if(d == 6 || d == 7 || d == 8) {
                cloud[j].first = (s+cloud[j].first) % n;
            }

            // 바구니 증가, 이동 기록 저장
            visited[cloud[j].first][cloud[j].second] = 1;
            arr[cloud[j].first][cloud[j].second] += 1;
        }

        // 대각선 확인
        for(int j=0; j<cloud.size(); j++) {
            int a[] = {-1, -1, 1, 1};
            int b[] = {-1, 1, -1, 1};
            for(int k=0; k<4; k++) {
                int dx = cloud[j].first + a[k];
                int dy = cloud[j].second + b[k];
                if(dx>=0 && dx<n && dy>=0 && dy<n && arr[dx][dy]>0) {
                    arr[cloud[j].first][cloud[j].second] += 1;
                }
            }
        }

        // 구름 생성
        vector<pair<int, int>> v;
        for(int x=0; x<n; x++) {
            for(int y=0; y<n; y++) {
                if(visited[x][y] == 0 && arr[x][y] >= 2) {
                    v.push_back({x, y});
                    arr[x][y] -= 2;
                }
            }
        }

        // for(int j=0; j<cloud.size(); j++)
        //     cout << cloud[j].first << " " << cloud[j].second << endl;
        // cout << endl;

        // 이전 구름 방문기록 지움, 새 구름으로 교체
        for(int j=0; j<cloud.size(); j++)
            visited[cloud[j].first][cloud[j].second] = 0;
        cloud = v;

        // for(int x=0; x<n; x++) {
        //     for(int y=0; y<n; y++) {
        //         cout << arr[x][y] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

    }

    int answer = 0;
    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            answer += arr[x][y];
        }
    }
    cout << answer;

    return 0;
}