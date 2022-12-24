#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt = 3;
char arr[6][6];
vector<pair<int, int>> teacher; // 선생님 좌표
string answer = "NO";

// 각 선생님들 상하좌우 체크, true -> 선생님에게 걸린 학생이 없음, false -> 선생님에게 걸린 학생이 있음
bool check() {
    for(int i=0; i<teacher.size(); i++) {
        int r = teacher[i].second;
        int t = teacher[i].first;
        int b = teacher[i].first;
        int l = teacher[i].second;
        while(true) {
            r += 1;
            if(r<n && arr[teacher[i].first][r] == 'S') return false;
            if(r>=n || (r<n && arr[teacher[i].first][r] == 'O')) break;
        }
        while(true) {
            t -= 1;
            if(t>=0 && arr[t][teacher[i].second] == 'S') return false;
            if(t<0 || (t>=0 && arr[t][teacher[i].second] == 'O')) break;
        }
        while(true) {
            b += 1;
            if(b<n && arr[b][teacher[i].second] == 'S') return false;
            if(b>=n || (b<n && arr[b][teacher[i].second] == 'O')) break;
        }
        while(true) {
            l -= 1;
            if(l>=0 && arr[teacher[i].first][l] == 'S') return false;
            if(l<0 || (l>=0 && arr[teacher[i].first][l] == 'O')) break;
        }
    }
    return true;
}

void Dfs(int idx) {
    if(!answer.compare("YES")) return;

    if(idx == cnt) {
        if(check()) {
            // cout << "teasdfsdaf" << endl;
            // for(int i=0; i<n; i++) {
            //     for(int j=0; j<n; j++) {
            //         cout << arr[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
            answer = "YES";
        }
        return;
    }

    // X인 곳에 벽을 재귀적으로 세움
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == 'X') {
                arr[i][j] = 'O';
                Dfs(idx+1);
                arr[i][j] = 'X';
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'T')
                teacher.push_back({i, j});
        }
    }
    Dfs(0);
    cout << answer;
    return 0;
}