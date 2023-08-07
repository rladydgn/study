#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[8][8];
vector<pair<int, int>> v;
int answer;

int up(int r, int c) {
    int cnt = 0;
    for(int i=r-1; i>=0; i--) {
        if(arr[i][c] == 6) break;
        if(arr[i][c] >= 1 && arr[i][c] <= 5) continue;
        if(arr[i][c] == 0) cnt++;
        arr[i][c]--;
    }
    return cnt;
}

void upclear(int r, int c) {
    for(int i=r-1; i>=0; i--) {
        if(arr[i][c] == 6) break;
        if(arr[i][c] >= 1 && arr[i][c] <= 5) continue;
        arr[i][c]++;
    }
}

int right(int r, int c) {
    int cnt = 0;
    for(int i=c+1; i<m; i++) {
        if(arr[r][i] == 6) break;
        if(arr[r][i] >= 1 && arr[r][i] <=5) continue;
        if(arr[r][i] == 0) cnt++;
        arr[r][i]--;
    }
    return cnt;
}

void rightclear(int r, int c) {
    for(int i=c+1; i<m; i++) {
        if(arr[r][i] == 6) break;
        if(arr[r][i] >= 1 && arr[r][i] <=5) continue;
        arr[r][i]++;
    }
}

int down(int r, int c) {
    int cnt = 0;
    for(int i=r+1; i<n; i++) {
        if(arr[i][c] == 6) break;
        if(arr[i][c] >= 1 && arr[i][c] <= 5) continue;
        if(arr[i][c] == 0) cnt++;
        arr[i][c]--;
    }
    return cnt;
}

void downclear(int r, int c) {
    for(int i=r+1; i<n; i++) {
        if(arr[i][c] == 6) break;
        if(arr[i][c] >= 1 && arr[i][c] <= 5) continue;
        arr[i][c]++;
    }
}

int left(int r, int c) {
    int cnt = 0;
    for(int i=c-1; i>=0; i--) {
        if(arr[r][i] == 6) break;
        if(arr[r][i] >= 1 && arr[r][i] <=5) continue;
        if(arr[r][i] == 0) cnt++;
        arr[r][i]--;
    }
    return cnt;
}

void leftclear(int r, int c) {
    int cnt = 0;
    for(int i=c-1; i>=0; i--) {
        if(arr[r][i] == 6) break;
        if(arr[r][i] >= 1 && arr[r][i] <=5) continue;
        arr[r][i]++;
    }
}

void func(int idx, int value) {
    if(answer == 0) return;
    if(idx == v.size()) {
        answer = min(value, answer);
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << answer;
        // cout << endl;
        return;
    }

    int r = v[idx].first;
    int c = v[idx].second;

    if(arr[r][c] == 1) {
        int cnt = right(r, c);
        func(idx+1, value-cnt);
        rightclear(r, c);

        cnt = down(r, c);
        func(idx+1, value-cnt);
        downclear(r, c);

        cnt = left(r, c);
        func(idx+1, value-cnt);
        leftclear(r, c);

        cnt = up(r, c);
        func(idx+1, value-cnt);
        upclear(r, c);
    }
    else if(arr[r][c] == 2) {
        int cnt = right(r, c);
        cnt += left(r, c);
        func(idx+1, value-cnt);
        rightclear(r, c);
        leftclear(r, c);

        cnt = up(r, c);
        cnt += down(r, c);
        func(idx+1, value-cnt);
        upclear(r, c);
        downclear(r, c);
    }
    else if(arr[r][c] == 3) {
        int cnt = right(r, c);
        cnt += down(r, c);
        func(idx+1, value-cnt);
        rightclear(r, c);
        downclear(r, c);

        cnt = down(r, c);
        cnt += left(r, c);
        func(idx+1, value-cnt);
        downclear(r, c);
        leftclear(r, c);

        cnt = left(r, c);
        cnt += up(r, c);
        func(idx+1, value-cnt);
        leftclear(r, c);
        upclear(r, c);

        cnt = up(r, c);
        cnt += right(r, c);
        func(idx+1, value-cnt);
        upclear(r, c);
        rightclear(r, c);
    }
    else if(arr[r][c] == 4) {
        int cnt = right(r, c);
        cnt += down(r, c);
        cnt += left(r, c);
        func(idx+1, value-cnt);
        rightclear(r, c);
        downclear(r, c);
        leftclear(r, c);

        cnt = down(r, c);
        cnt += left(r, c);
        cnt += up(r, c);
        func(idx+1, value-cnt);
        downclear(r, c);
        leftclear(r, c);
        upclear(r, c);

        cnt = left(r, c);
        cnt += up(r, c);
        cnt += right(r, c);
        func(idx+1, value-cnt);
        leftclear(r, c);
        upclear(r, c);
        rightclear(r, c);

        cnt = up(r, c);
        cnt += right(r, c);
        cnt += down(r, c);
        func(idx+1, value-cnt);
        upclear(r, c);
        rightclear(r, c);
        downclear(r, c);
    }
    else {
        int cnt = right(r, c);
        cnt += down(r, c);
        cnt += left(r, c);
        cnt += up(r, c);
        func(idx+1, value-cnt);
        rightclear(r, c);
        downclear(r, c);
        leftclear(r, c);
        upclear(r, c);
    }

}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] >= 1 && arr[i][j] <= 5) v.push_back({i, j});
            if(arr[i][j] == 0) answer++;
        }
    }
    func(0, answer);
    cout << answer;
    return 0;
}