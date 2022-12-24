#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n;
        cin >> n;
        char m1[n][n];
        int m2[n][n], visit[n][n][4];
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                string tmp;
                cin >> tmp;
                m1[j][k] = tmp[0];
                m2[j][k] = tmp[1] - '0';
                for(int l=0; l<4; l++)
                    visit[j][k][l] = 0;
            }
        }
        char before = 'B';
        pair<int, int> co = {0, 0};

        while(true) {
            char now = m1[co.first][co.second];
            pair<int, int> tmp = co;
            // F
            if((before == 'F' && now == 'F') || (before == 'R' && now == 'L') || (before == 'L' && now == 'R') || (before == 'B' && now == 'B')) {
                before = 'F';
                visit[co.first][co.second][0] += 1;
                co.first += m2[co.first][co.second];
            }
            // R
            else if((before == 'F' && now == 'R') || (before == 'R' && now == 'F') || (before == 'L' && now == 'B') || (before == 'B' && now == 'L')) {
                before = 'R';
                visit[co.first][co.second][1] += 1;
                co.second += m2[co.first][co.second];
            }
            // L
            else if((before == 'F' && now == 'L') || (before == 'R' && now == 'B') || (before == 'L' && now == 'F') || (before == 'B' && now == 'R')) {
                before = 'L';
                visit[co.first][co.second][2] += 1;
                co.second -= m2[co.first][co.second];
            }
            // B
            else {
                before = 'B';
                visit[co.first][co.second][3] += 1;
                co.first -= m2[co.first][co.second];
            }
            
            bool tf = false;
            for(int l=0; l<4; l++) {
                if(visit[tmp.first][tmp.second][l] == 2) {
                    cout << tmp.first << " " << tmp.second << "\n";
                    tf = true;
                    break;
                }
            }
            if(tf)
                break;
        }
    }
}