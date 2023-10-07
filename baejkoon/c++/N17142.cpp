#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int arr[50][50];
int answer = 99999999;

void dfs(int idx, vector<pair<int, int>> chosed, vector<pair<int, int>>& virus) {
    if(chosed.size() == m) {
        // visited에 해당 위치까지 오는데 걸린시간 + 1이 저장됨.
        int visited[50][50] = {0, };
        queue<pair<int, int>> q;

        for(int i=0; i<chosed.size(); i++) {
            // cout << chosed[i].first << " " << chosed[i].second << endl;
            q.push(chosed[i]);
            visited[chosed[i].first][chosed[i].second] = 1;
        }
        // cout << endl;

        int now_answer = 0;

        while(!q.empty()) {
            pair<int, int> p = q.front();
            if(arr[p.first][p.second] != 2) now_answer = max(now_answer, visited[p.first][p.second]-1);

            q.pop();

            // 해당 위치가 바이러스가 아니고, 소요 시간이 현재 정답과 같거나 크면 그대로 순회를 종료한다.
            // 이거 찾는데 몇시간 걸림. 처음에 arr[p.first][p.second] != 2 이걸 빼서
            // 비활성화된 바이러스까지 시간초 계산을 해버려 92%에서 틀렸음.
            if(arr[p.first][p.second] != 2 && visited[p.first][p.second] - 1 >= answer) return;

            int r[] = {0, 0, 1, -1};
            int c[] = {1, -1, 0, 0};
            for(int i=0; i<4; i++) {
                int dr = p.first + r[i];
                int dc = p.second + c[i];

                if(dr>=0 && dr<n && dc>=0 && dc<n && visited[dr][dc] == 0 && arr[dr][dc] != 1) {
                    visited[dr][dc] = visited[p.first][p.second] + 1;
                    q.push({dr, dc});
                }
            }
        }


        // 방문하지 않은 빈칸이 있을경우 그대로 중지한다.
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j] == 0 && visited[i][j] == 0) return;
            }
        }
        answer = min(answer, now_answer);
        return;
    }

    for(int i=idx; i<virus.size(); i++) {
        chosed.push_back(virus[i]);
        dfs(i+1, chosed, virus);
        chosed.pop_back();
    }
}

int main() {
    cin >> n >> m;
    vector<pair<int, int>> virus;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
            if(tmp == 2) {
                virus.push_back({i, j});
            }
        }
    }
    vector<pair<int, int>> v;
    dfs(0, v, virus);

    if(answer == 99999999) cout << -1;
    else cout << answer;
    return 0;
}