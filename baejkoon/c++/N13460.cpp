#include <iostream>
#include <string>
#include <queue>

using namespace std;

// 0 인덱스: 위로 이동기록, 1: 오른쪽, 2: 아래, 3: 왼쪽
int red_visited[10][10][4];
int blue_visited[10][10][4];
char arr[10][10];
int n, m;

struct Pos {
    int time;
    int red_row;
    int red_col;
    int blue_row;
    int blue_col;
};

int main() {
    cin >> n >> m;
    Pos p;
    p.time = 0;
    pair<int, int> hole;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            arr[i][j] = s[j];
            if(arr[i][j] == 'R') {
                p.red_row = i;
                p.red_col = j;
            }
            if(arr[i][j] == 'B') {
                p.blue_row = i;
                p.blue_col = j;
            }
            if(arr[i][j] == 'O') {
                hole.first = i;
                hole.second = j;
            }
        }
    }

    queue<Pos> q;
    q.push(p);
    while(!q.empty()) {
        Pos p = q.front();

        q.pop();

        if(p.time == 10) {
            cout << -1;
            return 0;
        }

        // 위로 기울이기
        if(red_visited[p.red_row][p.red_col][0] == 0 || blue_visited[p.blue_row][p.blue_col][0] == 0) {
            // 파란색 구슬 이동
            bool blue_check = false;
            int blue_idx = p.blue_row-1;
            bool blue_goal = false;
            blue_visited[p.blue_row][p.blue_col][0] = 1;
            while(blue_idx>=0) {
                // 바로 위에 빨간구슬 일경우
                if(arr[blue_idx][p.blue_col] == 'R') {
                    blue_visited[blue_idx][p.blue_col][0] = 1;
                    blue_check = true;
                    blue_idx--;
                    }
                // 벽
                else if(arr[blue_idx][p.blue_col] == '#') {
                    blue_idx++;
                    break;
                }
                // 구멍에 들어감
                else if(arr[blue_idx][p.blue_col] == 'O') {
                    blue_goal = true;
                    break;
                }
                // 그냥 이동
                else {
                    blue_visited[blue_idx][p.blue_col][0] = 1;
                    blue_idx--;
                }
            }

            // 빨간색 구슬 이동
            bool red_check = false;
            int red_idx = p.red_row-1;
            bool red_goal = false;
            red_visited[p.red_row][p.red_col][0] = 1;
            while(red_idx>=0) {
                // 바로 위에 파랑구슬 일경우
                if(arr[red_idx][p.red_col] == 'R') {
                    red_visited[red_idx][p.red_col][0] = 1;
                    red_check = true;
                    red_idx--;
                    }
                // 벽
                else if(arr[red_idx][p.red_col] == '#') {
                    red_idx++;
                    break;
                }
                // 구멍에 들어감
                else if(arr[red_idx][p.red_col] == 'O') {
                    red_goal = true;
                    break;
                }
                // 그냥 이동
                else {
                    red_visited[red_idx][p.red_col][0] = 1;
                    red_idx--;
                }
            }

            // 구멍에 안들어 갔을 경우 queue에 넣어줘야 함
            if(!red_goal && !blue_goal) {
                Pos tmp = {p.time+1, red_idx, p.red_col, blue_idx, p.blue_col};
                if(blue_check) {
                    tmp.blue_row += 1;
                }
                if(red_check) {
                    tmp.red_row += 1;
                }
                q.push(tmp);
            }

            if(red_goal && !blue_goal) {
                cout << p.time+1;
                return 0;
            }
        }

        // 오른쪽으로 기울이기
        if(red_visited[p.red_row][p.red_col][1] == 0 || blue_visited[p.blue_row][p.blue_col][1] == 0) {
            // 파란색 구슬 이동
            bool blue_check = false;
            int blue_idx = p.blue_col+1;
            bool blue_goal = false;
            blue_visited[p.blue_row][p.blue_col][1] = 1;
            while(blue_idx<m) {
                // 바로 오른쪽이 빨간구슬 일경우
                if(arr[p.blue_row][blue_idx] == 'R') {
                    blue_visited[p.blue_row][blue_idx][0] = 1;
                    blue_check = true;
                    blue_idx++;
                    }
                // 벽
                else if(arr[blue_idx][p.blue_col] == '#') {
                    blue_idx++;
                    break;
                }
                // 구멍에 들어감
                else if(arr[blue_idx][p.blue_col] == 'O') {
                    blue_goal = true;
                    break;
                }
                // 그냥 이동
                else {
                    blue_visited[blue_idx][p.blue_col][0] = 1;
                    blue_idx--;
                }
            }

            // 빨간색 구슬 이동
            bool red_check = false;
            int red_idx = p.red_row-1;
            bool red_goal = false;
            red_visited[p.red_row][p.red_col][0] = 1;
            while(red_idx>=0) {
                // 바로 위에 파랑구슬 일경우
                if(arr[red_idx][p.red_col] == 'R') {
                    red_visited[red_idx][p.red_col][0] = 1;
                    red_check = true;
                    red_idx--;
                    }
                // 벽
                else if(arr[red_idx][p.red_col] == '#') {
                    red_idx++;
                    break;
                }
                // 구멍에 들어감
                else if(arr[red_idx][p.red_col] == 'O') {
                    red_goal = true;
                    break;
                }
                // 그냥 이동
                else {
                    red_visited[red_idx][p.red_col][0] = 1;
                    red_idx--;
                }
            }

            // 구멍에 안들어 갔을 경우 queue에 넣어줘야 함
            if(!red_goal && !blue_goal) {
                Pos tmp = {p.time+1, red_idx, p.red_col, blue_idx, p.blue_col};
                if(blue_check) {
                    tmp.blue_row += 1;
                }
                if(red_check) {
                    tmp.red_row += 1;
                }
                q.push(tmp);
            }

            if(red_goal && !blue_goal) {
                cout << p.time+1;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}