#include <iostream>
#include <vector>

using namespace std;

int arr[20][20];
int n;
int answer;
int score[] = {0, 1, 10, 100, 1000};

bool isInclude(int row, int col, vector<int> like) {
    for(int i=0; i<like.size(); i++) {
        if(like[i] == arr[row][col]) return true;
    }
    return false;
}

void calHappy(int row, int column, vector<int>& like) {
    int cnt = 0;

    int r[] = {0, 0, 1, -1};
    int c[] = {1, -1, 0, 0};
    for(int k=0; k<4; k++) {
        int dr = row + r[k];
        int dc = column + c[k];

        if(dr>=0 && dr<n && dc>=0 && dc<n) {
            if(isInclude(dr, dc, like)) cnt++;
        }
    }
    answer += score[cnt];
}

void setPosition(int student, vector<int> like) {
    int cnt = -1;
    int empty = -1;
    int row = -1, column = -1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] != 0) continue;

            int now_cnt = 0;
            int now_empty = 0;

            int r[] = {0, 0, 1, -1};
            int c[] = {1, -1, 0, 0};
            for(int k=0; k<4; k++) {
                int dr = i + r[k];
                int dc = j + c[k];

                if(dr>=0 && dr<n && dc>=0 && dc<n) {
                    if(arr[dr][dc] == 0) now_empty++;
                    else if(isInclude(dr, dc, like)) now_cnt++;
                }
            }

            if(cnt < now_cnt || (cnt == now_cnt && empty < now_empty)) {
                cnt = now_cnt;
                empty = now_empty;
                row = i;
                column = j;
            }
        }
    }
    arr[row][column] = student;
}

int main() {
    cin >> n;
    vector<vector<int>> likes(n*n+1);
    // cout << likes.size() << endl;
    for(int i=0; i<n*n; i++) {
        int student;
        vector<int> like(4);
        cin >> student;
        for(int j=0; j<4; j++) cin >> like[j];
        setPosition(student, like);
        likes[student] = like;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            calHappy(i, j, likes[arr[i][j]]);
            // cout << arr[i][j] << " ";
        }
        // cout << endl;
    }
    cout << answer;
    return 0;
}