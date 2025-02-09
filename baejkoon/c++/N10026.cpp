#include <iostream>
#include <string>

using namespace std;

int n;
char arr[100][100];
int visited1[100][100], visited2[100][100];

void Dfs(int r, int c, int state) {
    int rr[] = {0, 0, 1, -1};
    int cc[] = {1, -1, 0, 0};
    if(state == 0) {
        visited1[r][c] = 1;

        for(int i=0; i<4; i++) {
            int dr = r + rr[i];
            int dc = c + cc[i];

            if(dr>=0 && dr<n && dc>=0 && dc<n && visited1[dr][dc] == 0 && arr[dr][dc] == arr[r][c]) {
                Dfs(dr, dc, state);
            }
        }
    }
    else if(state == 1) {
        visited2[r][c] = 1;

        for(int i=0; i<4; i++) {
            int dr = r + rr[i];
            int dc = c + cc[i];

            if(dr>=0 && dr<n && dc>=0 && dc<n && visited2[dr][dc] == 0 && (arr[dr][dc] == arr[r][c] || (arr[r][c] == 'G' && arr[dr][dc] == 'R') || (arr[r][c] == 'R' && arr[dr][dc] == 'G'))) {
                Dfs(dr, dc, state);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            arr[i][j] = s[j];
        }
    }

    int answer1 = 0, answer2 = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visited1[i][j] == 0) {
                Dfs(i, j, 0);
                answer1++;
            }
            if(visited2[i][j] == 0) {
                Dfs(i, j, 1);
                answer2++;
            }
        }
    }
    cout << answer1 << " " << answer2;

    return 0;
}